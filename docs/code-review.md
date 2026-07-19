# Code review notes and task list

From a review pass on 2026-07-18 (leak hunting under Linux LeakSanitizer,
UB probes under AddressSanitizer and libgmalloc, plus a read-through of
ownership and header structure). A follow-up pass the same day worked
through the queue; items are marked **[fixed]**, **[resolved]** (decided
with rationale, no code change warranted), or **[open]**.

## P1 — crashes / correctness

1. **[fixed] ChainingMapper double-delete (intermittent crash).**
   Root cause was not in `ChainingMapper::map` itself: `BGPSimplifier`
   (SWObjectDuplicator.hpp) could put the same node into its output tree
   twice, so the tree double-deleted its own child. Two paths:
   (a) `tableDisjunction` added each child to the new disjunction *and*
   `pendingConjunction` added it again to the outer pending conjunction;
   (b) `defaultGraphPattern`/`namedGraphPattern` add a fresh BGP to an
   existing `nestingConj` at creation, and `flushConjunction` added
   `lastBGP` to it a second time (sequence BGP-Filter-BGP-Filter inside
   one conjunction). Which path fired depended on pointer-keyed map
   iteration order upstream — hence the heisenbug (8/25 plain runs
   crashed; ASan/gmalloc/lldb layouts hid it). Diagnosed with a
   `SWOBJ_DEBUG_DOUBLE_DELETE` build (kept, compiled out by default):
   a `TableOperation` live-set plus an `OpCollector` tree-overlap check
   in `ChainingMapper::map`. Final shape: `tableDisjunction` captures
   the outer conjunction once, processes each disjunct in a fresh
   context, and the completed disjunction joins the pending conjunction
   as a whole (the per-child add was the double-owner; per-child
   context restore alone orphaned the `flushConjunction` husk, which
   LSan caught as 14 leaked conjunctions). `flushConjunction` also
   guards against re-adding a BGP the creation path already added.
   After the fix: 0/30 failures in release and 0/30 in the
   instrumented build. `test_QueryMap` now gates CI, including the
   sanitizer job (the suite's residual success-path leaks were
   `Bind::~Bind` — see the closed threads below).

2. **[fixed] Eager-filter semantic-action over-fire.** Step 6 candidate
   filtering now runs with the handler suppressed (the Test-extension
   `fail` interpretation is handler-independent and still applies);
   the accepted matching re-validates its chosen (triple, constraint)
   pairs with the handler enabled in step 10, and every rejection path
   in the matching loop rolls back to a mark taken at the top of the
   iteration (previously step 9 EXTENDS-constraint bindings could
   survive a rejected matching).

3. **[fixed] SPARQL `md5`/`sha1`/`sha256`/`sha384`/`sha512` builtins.**
   Implemented in the new self-contained `lib/SWCrypto.hpp` (MD5 per
   RFC 1321 with the sine-derived table computed at startup; SHA per
   FIPS 180-4; lower-case hex over UTF-8 bytes), verified against
   system `md5`/`shasum` on empty/multi-block/UTF-8 inputs. Replaces
   the dead Crypto++ `CRYPT_LIB` path; also fixed an out-of-bounds
   `args[2]` in the old TypeError paths, accepts xsd:string per the
   errata, registered SHA384, and replaced the `CRYPT_LIB`-gated
   `RAND()` (constant 0.99999 fallback!) with `<random>`.
   `test_SPARQL11` is fully green.

4. **[fixed] `function_library` CSV `<foo>`-as-IRI.** Re-enabled the
   csv regex IRI branch in `lib/ResultSet.cpp`, mirroring the tsv
   pattern. Conformant SPARQL 1.1 CSV results serialize IRIs bare, so
   the branch only affects cells that literally look like `<foo>`;
   `test_SPARQL` (63/63) and the SPARQL 1.1 csv-tsv results tests all
   pass.

## P2 — leaks / ownership

5. **[fixed]** `restoreFilter` leaked the `FilterExpressions` carrier
   per FILTER clause (LSan: 104 × 24 B). Deleted after its expressions
   move into the `Filter` op.

6. **[fixed]** `StarVarSet::project` leaked a fresh `TTermExpression`
   per projected variable. Now uses owning `ExpressionAlias`.

7. **[fixed] Bison error-path leaks — all 8 grammars.**
   `ShExCParser.ypp` first: plain deletes for owned pointer types,
   none for AtomFactory-interned values, element-wise frees for
   vector types, and an `emptyShape`-sentinel guard. Landing them
   surfaced two action-ownership bugs, both fixed (`addFacet` deleted
   the duplicate facet before `error()` threw; the `start` action
   could error after consuming `$3/$4`). Then replicated to
   SPARQLParser, MapSetParser, TurtleParser, TrigParser,
   JSONresultsParser, SPARQLalgebraParser and SQLParser with the same
   classification, plus two rules the SPARQL bisect taught:
   *no destructor for the start-result type* (`<p_Operation>` — the
   accept-path cleanup would destroy the tree just handed to the
   caller) and *none for types that park driver-owned state in
   mid-rule slots* (`<p_TableOperation>` ↔ `driver.curOp`).
   `~MapSetDriver` also gained the stranded-state cleanup (and its
   `restoreFilter` had the same carrier leak originally fixed only in
   the SPARQL copy; `curOp` was missing from its initializer list).
   The SQL grammar carries token destructors only — its `sql::*`
   nonterminal ownership is tangled in mid-rule parking and its error
   paths parse trusted fixtures.

8. **[fixed] Driver error-path state.** `~SPARQLDriver` now frees a
   stranded `curFilter` (with its expressions) and `curOp` (which owns
   `curBGP` — they are conjoined on creation in
   `ensureBasicGraphPattern`). `~ShExDriver` frees stranded
   `pendingRestricts`.

9. **[fixed]** `getRDFLiteral`'s typed-literal early returns now funnel
   through one exit that deletes a stray `p_LANGTAG`.

## P3 — RAII / API modernization

10. **[resolved] `ProductionVector` vs `NoDelProductionVector`.**
    For the ShEx AST, raw pointers with owning destructors is the
    *correct* design, not legacy debt: the bison `%union` cannot hold
    smart pointers, and the parser's `emptyShape` sentinel must never
    be owned by a container. Those destructors are centralized and
    LSan-verified. The SPARQL AST migration to
    `std::vector<std::unique_ptr<...>>` is explicitly declined: the
    AST is stable, the churn would touch every parser action and
    duplicator for no behavioural gain, and the property the
    migration would buy — ownership mistakes can't survive unnoticed —
    is now enforced mechanically instead: a dedicated ASan/LSan CI
    job gates `test_DAWG`, `test_ShEx`, `test_QueryMap` and the
    ShExMap CLI, all leak-clean. (That guardrail is what caught
    `Bind::~Bind` never deleting its expression — the real ownership
    bug hiding in the AST — along with the double-adds in
    `BGPSimplifier`.)

11. **[fixed]** `ParserDriver` namespace-map ownership is now a
    `std::unique_ptr` (engaged unless a map was borrowed) plus a plain
    observer pointer; the `freeNamespaces` bool is gone.

12. **[fixed]** test harness caches (`tests/test_ShEx.cpp`) use
    `std::map<std::string, std::unique_ptr<Entry>>`.

## P4 — templating / duplication

13. **[resolved] `dynamic_cast` dispatch in the ShEx validator.**
    Reviewed against a wholesale visitor conversion and deliberately
    kept: the AST is the closed, spec-defined ShEx 2.1 node set; every
    chain was audited to cover it, and remaining fall-throughs are
    intentional no-ops (e.g. leaf types in RefWalk). Converting the
    recursive interval/SORBE algorithms to visitors would replace
    direct pattern-matching with result-slot boilerplate for no
    behavioural gain. Revisit only if the AST ever grows beyond the
    spec.

14. **[resolved] Grammar action boilerplate.** Evaluated and declined:
    the `_Q..._E_Star/Plus` accumulation actions are two lines each in
    bison C++; the Jison-style `appendTo` helper exists to work around
    string-template actions and would only add indirection here.

15. **[resolved] Interval/cardinality arithmetic.** Already unified:
    the scanner's `CardPOD` is the `%union`-mandated POD carrier
    (converted via `wrapCard`), and both it and the interval algebra
    share `ShEx::Unbounded`. No duplicated arithmetic remains.

## P5 — build / header layout

16. **[fixed] Logging facade.** `SWObjects.hpp` now includes only
    `lib/LoggingFacade.hpp` (severity/channel enums, per-channel
    levels, `enabled()`, a buffering `LogRecord`, and the
    `w3c_sw_LOG(Channel, level)` macro); the Boost.Log machinery
    stays in `Logging.hpp`, included only where logging is
    *configured* (bin/, tests), and `lib/Logging.cpp` is the one
    library TU that forwards records to Boost.Log. All 196
    `BOOST_LOG_SEV(...)` call sites were rewritten to `w3c_sw_LOG`.
    Two wins beyond decoupling: library compile CPU dropped again
    (~81s → ~61s, from ~111s originally, PCH included), and the
    facade pre-filters *before* evaluating the streamed expression —
    previously, with no sink prepared, Boost accepted every record
    (no filter installed until `prepare()`), so every log site paid
    for argument evaluation and formatting in non-logging runs.
    Header-only stays the verdict for SimpleServer/SQLizer/WEBserver
    (one-TU consumers).

17. **[fixed]** `SWObjects_STAND_ALONE` → explicit
    `w3c_sw_DEFINE_LOGGER_GLOBALS` invoked from SWObjects.cpp (a
    macro-conditional block is invisible to a precompiled header).

## P6 — performance

18. **[fixed]** SORBE forms memoized per triple expression on the
    `Validator` (freed in `~Validator`).

19. **[fixed]** Sound `(node, label)` result memo (no handler, no
    cyclic assumption).

20. **[fixed]** Neighbourhood extraction uses the BGP SP/PO indexes
    (`getTripleIterator`) instead of scanning every triple per focus
    node — linear in the neighbourhood, not the graph. Also fixed a
    latent UB in `triple_iterator`'s range constructor, which
    dereferenced the end iterator of an empty range.

21. **[fixed] `Matchings` pruning.** The enumeration is now a DFS with
    per-TC upper bounds (`SorbeExpr::maxCounts`: product of enclosing
    cardinality maxima, Unbounded-aware — a necessary condition on
    bags, in the spirit of jena's `FeasibleMatchingsIterator`).
    Partial assignments that give a TC more triples than its bound are
    backtracked before the cartesian subtree is expanded. Full
    interval-based feasibility (sufficient conditions) remains
    possible if pathological workloads appear.

22. **[fixed]** test-harness `GraphIndex` uses a `(subject,
    predicate) → object` map.

## Formerly open threads — all closed 2026-07-19

- **`test_QueryMap` success-path leaks: [fixed].** The root cause was
  `Bind::~Bind` never deleting `m_expr` — every deleted `Bind`
  (parser originals, duplicator generations, MapSet rule ASTs) leaked
  its expression tree; the MapSetParser `ArgList`s were the same hole
  reached through stored rules. All five `new Bind(...)` sites pass
  freshly-built expressions, so the destructor now owns it. Also
  fixed nearby: `GraphAndServiceMerger` left `elideSubSelect`
  uninitialized, and `Alternatives::instantiate` leaked the partial
  union when an unmatchable alternative returned NULL. macOS
  `leaks --atExit`: 0 bytes on the healthCare suite (was 144 leaks).
- **Item 7 (`%destructor` replication): [fixed]** — see item 7.
- **Item 10 (`unique_ptr` migration): [resolved-declined]** with the
  sanitizer CI guardrail — see item 10.
- **Item 16 (logging facade): [fixed]** — see item 16.
- `BGPSimplifier`'s conjunction bookkeeping remains intricate; the
  `SWOBJ_DEBUG_DOUBLE_DELETE` build (define it in CMAKE_CXX_FLAGS)
  turns aliasing into a deterministic abort with a printed tree, and
  now also reports nodes a `map()` call created but dropped
  (`OpCollector` reachability diff over the live-op set).
- CI: the `sanitize` job (ubuntu, `-fsanitize=address`,
  `ASAN_OPTIONS=detect_leaks=1`) gates `test_DAWG`, `test_ShEx`,
  `test_QueryMap`, and the ShExMap CLI.
