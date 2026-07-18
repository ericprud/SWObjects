# Code review notes and task list

From a review pass on 2026-07-18 (leak hunting under Linux LeakSanitizer,
UB probes under AddressSanitizer, plus a read-through of ownership and
header structure). Items fixed during the pass are marked **[fixed]**;
the rest are queued for follow-up work, roughly in priority order.
Suggested workflow: pick an item, reproduce with the command given,
fix, and run `ctest --test-dir build` plus the item's repro.

## P1 — crashes / correctness

1. **ChainingMapper double-delete (intermittent crash).**
   `lib/ChainingMapper.hpp` `map()`: `delete op` after `BGPSimplifier`
   walks it. The rewriter (`QueryWalker::mapQuery`) can produce trees
   sharing subexpressions, so the tree-delete double-frees. Crashes
   `test_QueryMap bsbm/pieces/transformQuery` on some heap layouts
   (deterministic under `lldb` because ASLR is off; hidden under ASan
   and MallocStackLogging).
   *Suggested approach*: make `QueryWalker`'s sharing explicit — either
   clone at the sharing points (SWObjectDuplicator) or count references
   in the rewrite products. Verify with repeated
   `lldb -b -o run -o quit build/test_QueryMap`.

2. **Eager-filter semantic-action over-fire on unused candidates.**
   `lib/ShExSchema.cpp` `satisfiesShape` step 6 validates every
   (triple, constraint) candidate; a candidate that validates but is
   not chosen by the accepted matching still ran nested shapes' step-10
   semantic actions. `SemActHandler::mark`/`rollback` scopes bindings
   to *successful* subtrees, but successful-unused candidates still
   leak bindings into e.g. ShExMap. Faithful fix: dispatch semantic
   actions from the accepted solution only (re-walk the winning
   matching, re-validating value expressions with the handler enabled
   and pre-filter dispatch disabled).

3. **SPARQL `md5`/`sha*` builtins unimplemented** (8 known
   `test_SPARQL11` failures). `TTerm::FUNC_md5` etc. exist but no
   evaluator binds them. A small digest implementation (or vendored
   single-file SHA/MD5) in `lib/SWObjects.cpp`'s BuiltIn section would
   turn the suite fully green.

4. **`function_library` CSV `<foo>`-as-IRI** (1 known `test_SPARQL`
   failure). `lib/ResultSet.cpp` csv regex has the IRI branch disabled
   (`// disabled`) since ~2013 while the 2012 test expects it. Decide:
   re-enable for `text/csv` *input* (keeping SPARQL 1.1 CSV *results*
   conformance in `test_SPARQL11` csv tests) or retire the test.

## P2 — leaks / ownership

5. **[fixed]** `restoreFilter` leaked the `FilterExpressions` carrier
   per FILTER clause (LSan: 104 × 24 B via `SPARQLParser.ypp` +
   hangers-on). Now deleted after its expressions move into the
   `Filter` op.

6. **[fixed]** `StarVarSet::project` leaked a fresh `TTermExpression`
   per projected variable (LSan: 100 × 64 B) because it wrapped them
   in a deliberately non-owning alias. Now uses owning
   `ExpressionAlias`.

7. **Bison error-path leaks.** None of the grammars declare
   `%destructor`, so semantic values on the stack leak when a parse
   fails. LSan-confirmed for ShExC: after the fixes above, `test_ShEx`
   under LSan reports exactly this — ~18.5 KB / 222 allocations, all
   through `ShExDriver::parse` from the negativeSyntax suites (AST
   fragments from actions around `ShExCParser.ypp:696/835/985/1009`
   plus scanner token strings from `ShExCScanner.lpp:155-165`); the
   success paths (`test_DAWG`, `bin/sparql` ShExMap run) are clean.
   Adding `%destructor` per union member is mechanical but touchy:
   *do not delete* AtomFactory-interned values (`p_URI`, `p_TTerm`,
   `p_Literal` — the factory owns them), guard `p_SE`/`p_SEs`
   elements against the `driver.emptyShape` sentinel, and remember
   `p_SEs`/`p_TEs`/vector types own their elements. Do
   ShExCParser.ypp first as the template, verify with the docker LSan
   run, then replicate to the other grammars.

8. **`YaccDriver` error-path state.** `SPARQLDriver::curFilter`,
   `curBGP` etc. leak if a throw unwinds mid-parse. Consider owning
   these as `std::unique_ptr` in the drivers (release() at the
   handoff points).

9. **`getRDFLiteral` numeric branches ignore `p_LANGTAG`.**
   `lib/SWObjects.cpp`: the integer/decimal/double/boolean early
   returns drop a passed langtag without deleting it (invalid input,
   but a leak if it happens). Delete or reject explicitly.

## P3 — RAII / API modernization

10. **`ProductionVector` vs `NoDelProductionVector`.** The owning /
    non-owning split is by class choice with manual delete loops in
    destructors. A cleaner shape: one
    `template <typename T, bool Owning>` (or move owning containers to
    `std::vector<std::unique_ptr<const T>>`) so ownership is visible in
    the type. Big mechanical change; start with new code only
    (`ShEx::*` vectors) and leave the SPARQL AST for a dedicated pass.
    Note the TTerm/"POS" objects themselves are fine: AtomFactory owns
    them (interning maps freed in `~AtomFactory`), and their private
    constructors/destructors enforce it.

11. **`NamespaceMap` ownership flag.** `ParserDriver::freeNamespaces`
    bool + raw pointer is a hand-rolled maybe-owner; a
    `std::unique_ptr<NamespaceMap>` plus a non-owning observer pointer
    expresses it directly.

12. **test harness caches** (`tests/test_ShEx.cpp` SchemaCache /
    DataCache) use raw `new`/manual dtor loops — safe today, but
    `std::map<std::string, std::unique_ptr<Entry>>` removes the
    footgun.

## P4 — templating / duplication

13. **`dynamic_cast` dispatch in the ShEx validator.**
    `lib/ShExSchema.cpp` re-implements type dispatch with
    `dynamic_cast` chains in ~8 places (RefWalk, SorbeExpr, predicate
    collection, materializer in ShExMap.cpp) although
    `ShapeExprVisitor`/`TripleExprVisitor` exist. Converting the
    walkers to visitors removes the chains and the risk of missing a
    case when the AST grows.

14. **Grammar action boilerplate.** The `_Q..._E_Star/Plus` vector
    accumulation actions repeat ~20 times per grammar. A tiny driver
    template (`appendTo(vector*, elt)` as in ShExJison's helpers)
    would halve the .ypp action volume. Cosmetic; do when touching a
    grammar anyway.

15. **Interval/cardinality arithmetic** in `ShExSchema.cpp` and the
    `REPEAT_RANGE` handling in the scanner both re-implement
    min/max-with-unbounded logic; unify on `ShEx::Cardinality`.

## P5 — build / header layout

16. **Header-only is fine here — with one exception.** With ~10
    library TUs, ~25 generated parser TUs, and one-TU test/binary
    targets, keeping SimpleServer/SQLizer/WEBserver as headers is
    reasonable (each has 1–2 consumers; splitting buys little).
    The exception is `SWObjects.hpp` → `Logging.hpp` → Boost.Log/
    Phoenix/Thread in *every* TU. **[fixed]** for build time via
    `target_precompile_headers` (compile CPU ~111s → ~81s for the
    library). The structural fix, if wanted later: put a minimal
    logging facade in SWObjects.hpp and move the Boost.Log machinery
    behind a .cpp; that also unblocks non-Boost.Log consumers.

17. **[fixed]** `SWObjects_STAND_ALONE` macro-conditional definitions
    in Logging.hpp broke under PCH (macro state isn't seen by a
    precompiled header). Replaced with an explicit
    `w3c_sw_DEFINE_LOGGER_GLOBALS` invoked from SWObjects.cpp.

## P6 — performance

18. **[fixed]** ShEx SORBE forms were rebuilt on every shape
    evaluation; now memoized per triple expression on the `Validator`.

19. **[fixed]** Added a sound `(node, label)` result memo to the
    validator (used only without semantic-action handlers, and only
    for results that took no cyclic assumption).

20. **ShEx neighborhood extraction scans all triples**
    (`satisfiesShape` step 2 iterates the whole graph per focus node).
    `BasicGraphPattern` has SP/PO/OS indexes; using them makes
    validation linear in the neighborhood instead of the graph.

21. **`Matchings` is an unpruned cartesian product.** Fine for
    shexTest-sized neighborhoods; pathological EXTRA/multi-candidate
    data can explode. jena's `FeasibleMatchingsIterator` prunes with
    per-constraint interval bounds — port it if real workloads hit
    this.

22. **`GraphIndex::getObject`** in tests/test_ShEx.cpp is O(triples)
    per lookup over the manifest graph (~17k triples × ~1700 entries).
    Harness-only; index it if registration time ever matters.
