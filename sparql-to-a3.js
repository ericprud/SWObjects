/* sparql-to-a3.js - compile a sparqljs AST to an Algae 3 script, per
 * ../algae3/doc/sparql-to-algae3.md section 3 (the top-down structural
 * translation: groups become parentheses, patterns stay where they are,
 * filters apply where written). The emitted script defaults to
 * require eval-topdown; evaluating it under the engine's bottom-up mode
 * gives the SPARQL-algebra reading of the same shape (section 4's full
 * scope/fresh-variable compilation - exact bottom-up SPARQL fidelity on a
 * top-down-only engine - is not needed here and remains future work).
 *
 * Coverage: SELECT (DISTINCT, ORDER/LIMIT/OFFSET, GROUP BY, HAVING,
 * aggregates incl. nested-in-expression), subselects (scope pipelines),
 * ASK (test), CONSTRUCT (ask+assert), FROM/FROM NAMED (load), GRAPH (in),
 * OPTIONAL (~), UNION (|&), MINUS (|!), FILTER ({...}, NOT EXISTS -> !),
 * BIND (let), VALUES (bindings), IN -> oneof, builtin map per
 * examples/manifesty.yaml. Throws Error("unsupported: ...") otherwise
 * (property paths, SERVICE, DESCRIBE, EXISTS-as-filter).
 */

"use strict";

/* ── term rendering ─────────────────────────────────────────────────────── */

function term(t) {
  if (!t || t.termType == null) throw new Error("unsupported: non-term " + JSON.stringify(t));
  switch (t.termType) {
  case "NamedNode": return "<" + t.value + ">";
  case "Variable":  return "?" + t.value;
  case "BlankNode": return "_:" + t.value.replace(/[^A-Za-z0-9_]/g, "_");
  case "Literal": {
    const lex = '"' + t.value.replace(/\\/g, "\\\\").replace(/"/g, '\\"') + '"';
    const dt = t.datatype?.value;
    if (t.language) return lex + "@" + t.language;
    if (dt === "http://www.w3.org/2001/XMLSchema#integer"
     || dt === "http://www.w3.org/2001/XMLSchema#decimal"
     || dt === "http://www.w3.org/2001/XMLSchema#double") return t.value;
    if (dt === "http://www.w3.org/2001/XMLSchema#boolean") return t.value;
    if (dt && dt !== "http://www.w3.org/2001/XMLSchema#string") return lex + "^^<" + dt + ">";
    return lex;
  }
  default: throw new Error("unsupported term type: " + t.termType);
  }
}

const RDF_TYPE = "http://www.w3.org/1999/02/22-rdf-syntax-ns#type";

function verb(p) {
  if (p.termType === "NamedNode" && p.value === RDF_TYPE) return "a";
  if (p.termType === "NamedNode" || p.termType === "Variable") return term(p);
  throw new Error("unsupported: property paths"); // sparqljs path objects lack termType
}

/* ── expressions ────────────────────────────────────────────────────────── */

const FUNS = { // SPARQL builtin -> a3 call name (manifesty.yaml map)
  bound: "bound", if: "if", coalesce: "coalesce", str: "str",
  strafter: "strafter", replace: "replace", concat: "concat",
  regex: "regex", datatype: "datatype", lang: "lang", iri: "iri", uri: "iri",
  isiri: "isIRI", isuri: "isURI", isblank: "isBlank", isliteral: "isLiteral",
};
const AGGS = new Set(["count", "sum", "min", "max", "avg", "sample", "group_concat"]);

function expr(e, ctx) {
  if (e.termType === "Variable" && ctx?.rename && !ctx.inScope.has("?" + e.value))
    return ctx.fresh(e.value); // rule 2: out-of-scope -> renamed apart
  if (e.termType != null) return term(e);
  if (e.type === "aggregate") {
    const name = e.aggregation.toLowerCase();
    if (!AGGS.has(name)) throw new Error("unsupported aggregate: " + e.aggregation);
    const arg = e.expression?.termType === "Wildcard" ? "" : expr(e.expression, ctx);
    const inner = (e.distinct ? "distinct " : "") + arg;
    if (name === "group_concat") {
      /* separators are plain second arguments (settled design) */
      const sep = '"' + (e.separator ?? " ").replace(/"/g, '\\"') + '"';
      return `group_concat(${inner}, ${sep})`;
    }
    return `${name}(${inner})`;
  }
  if (e.type === "operation" || e.type === "operator" ) {
    const op = e.operator.toLowerCase();
    const a = e.args ?? [];
    const bin = { "=": "==", "!=": "!=", "<": "<", ">": ">", "<=": "<=", ">=": ">=",
                  "&&": "&&", "||": "||", "+": "+", "-": "-", "*": "*", "/": "/" };
    if (op in bin && a.length === 2)
      return `(${expr(a[0], ctx)} ${bin[op]} ${expr(a[1], ctx)})`;
    if (op === "-" && a.length === 1) return `(- ${expr(a[0], ctx)})`;
    if (op === "!" && a.length === 1) return `(! ${expr(a[0], ctx)})`;
    if (op === "in")  /* `in` is the GRAPH keyword; oneof stands in (settled) */
      return `oneof(${expr(a[0], ctx)}, ${a[1].map(x => expr(x, ctx)).join(", ")})`;
    if (op === "notin")
      return `(! oneof(${expr(a[0], ctx)}, ${a[1].map(x => expr(x, ctx)).join(", ")}))`;
    if (op === "notexists" || op === "exists")
      throw new Error("EXISTS belongs in pattern position"); // handled by filterPattern
    if (op in FUNS)
      return `${FUNS[op]}(${a.map(x => expr(x, ctx)).join(", ")})`;
    throw new Error("unsupported operator: " + e.operator);
  }
  if (e.type === "functionCall")
    return `${term(e.function)}(${e.args.map(x => expr(x, ctx)).join(", ")})`;
  throw new Error("unsupported expression: " + (e.type ?? JSON.stringify(e)));
}

/* ── patterns ───────────────────────────────────────────────────────────── */

function bgp(triples, ind) {
  /* Turtle-ish: group consecutive triples sharing a subject with `;` */
  const lines = [];
  let i = 0;
  while (i < triples.length) {
    const s = term(triples[i].subject);
    const parts = [];
    let j = i;
    while (j < triples.length && term(triples[j].subject) === s) {
      parts.push(verb(triples[j].predicate) + " " + term(triples[j].object));
      ++j;
    }
    lines.push(s + " " + parts.join(" ;\n" + ind + " ".repeat(s.length + 1)));
    i = j;
  }
  return lines.join(" .\n" + ind);
}

/** wrap a group's compilation in scope(...) share(its in-scope vars) */
function scoped(patterns, ind, ctx) {
  const V = [...inScope(patterns)];
  const inner = { ...ctx, inScope: inScope(patterns, new Set(ctx.inScope)) };
  return "scope ( " + group(patterns, ind + "  ", inner) + " )"
       + " share (" + V.join(" ") + ")";
}

/** compile a sparqljs pattern ARRAY (one group's contents).
 * ctx = {mode:"topdown"|"bottomup", inScope:Set, fresh, rename:bool} */
function group(patterns, ind, ctx = { mode: "topdown" }) {
  const bu = ctx.mode === "bottomup";
  const ectx = bu ? { ...ctx, rename: true,
                      inScope: inScope(patterns, new Set(ctx.inScope)) } : undefined;
  const filters = []; // bottom-up: group filters apply after all joins
  const parts = []; // each a conjunct string
  for (const p of patterns) {
    switch (p.type) {
    case "bgp":
      if (p.triples.length) parts.push(bgp(p.triples, ind));
      break;
    case "optional":
      if (bu) {
	/* rule 3: absorb the optional group's IMMEDIATE filters - they sit
	 * outside the scope, at the LeftJoin, where outer names stay visible */
	const direct = p.patterns.filter(x => x.type === "filter"
					 && x.expression?.operator?.toLowerCase() !== "notexists");
	const rest = p.patterns.filter(x => !direct.includes(x));
	const joinScope = inScope(rest, new Set(ectx.inScope));
	const jctx = { ...ctx, rename: true, inScope: joinScope };
	let o = scoped(rest, ind + "  ", ctx);
	for (const f of direct)
	    o += " .\n" + ind + "  {" + expr(f.expression, jctx) + "}";
	parts.push(direct.length ? "~( " + o + " )" : "~ " + o);
      } else
	parts.push("~( " + group(p.patterns, ind + "   ", ctx) + " )");
      break;
    case "minus": {
      /* MINUS binds to the group built so far: (acc |! (P)) */
      const acc = parts.length ? parts.join(" .\n" + ind) : "";
      const rhs = bu ? "( " + scoped(p.patterns, ind + "     ", ctx) + " )"
                     : "( " + group(p.patterns, ind + "     ", ctx) + " )";
      parts.length = 0;
      parts.push(acc ? "( " + acc + "\n" + ind + "  |! " + rhs + " )" : "|! " + rhs);
      break;
    }
    case "union":
      parts.push("( " + p.patterns.map(b => {
        const ps = b.type === "group" ? b.patterns : [b];
        return bu ? scoped(ps, ind + "  ", ctx) : group(ps, ind + "  ", ctx);
      }).join("\n" + ind + "|&\n" + ind + "  ") + " )");
      break;
    case "group":
      parts.push(bu ? scoped(p.patterns, ind + "  ", ctx)
                    : "( " + group(p.patterns, ind + "  ", ctx) + " )");
      break;
    case "graph":
      parts.push("in " + term(p.name) + " ( "
        + (bu ? scoped(p.patterns, ind + "  ", ctx) : group(p.patterns, ind + "  ", ctx)) + " )");
      break;
    case "filter": {
      const op = p.expression?.operator?.toLowerCase();
      if (op === "notexists") {
        const arg = p.expression.args[0];
        /* NB in bottom-up mode ! evaluates as Minus; SPARQL NOT EXISTS's
         * substitution semantics are the top-down reading */
        parts.push("!( " + group(arg.patterns ?? [arg], ind + "   ", ctx) + " )");
      }
      else if (op === "exists")
        throw new Error("unsupported: FILTER EXISTS (use the pattern directly)");
      else if (bu)
        filters.push("{" + expr(p.expression, ectx) + "}"); // group filters join last
      else
        parts.push("{" + expr(p.expression) + "}");
      break;
    }
    case "bind":
      parts.push("let (" + term(p.variable) + " " + expr(p.expression, ectx) + ")");
      break;
    case "values":
      parts.push(valuesBlock(p.values, ind));
      break;
    case "query":
      parts.push(subselect(p, ind, ctx));
      break;
    case "service":
      throw new Error("unsupported: SERVICE");
    default:
      throw new Error("unsupported pattern: " + p.type);
    }
  }
  parts.push(...filters);
  return parts.join(" .\n" + ind);
}

function valuesBlock(values, ind) {
  const vars = Object.keys(values[0] ?? {}); // "?name" keys
  const rows = values.map(r =>
    "(" + vars.map(v => r[v] === undefined ? "UNDEF" : term(r[v])).join(" ") + ")");
  return "bindings (" + vars.join(" ") + ") { " + rows.join(" ") + " }";
}

/* ── section 4 (bottom-up) machinery ────────────────────────────────────── */

/** SPARQL in-scope variables of a pattern list (18.2.1-ish) */
function inScope(patterns, into = new Set()) {
  for (const p of patterns ?? []) {
    switch (p.type) {
    case "bgp":
      for (const t of p.triples)
        for (const k of ["subject", "predicate", "object"])
          if (t[k].termType === "Variable") into.add("?" + t[k].value);
      break;
    case "bind": into.add(term(p.variable)); break;
    case "values": for (const v of Object.keys(p.values[0] ?? {})) into.add(v); break;
    case "graph":
      if (p.name.termType === "Variable") into.add(term(p.name));
      inScope(p.patterns, into); break;
    case "optional": case "group": case "union":
      inScope(p.patterns, into); break;
    case "query":
      for (const v of p.variables ?? [])
        if (v.termType === "Variable") into.add(term(v));
        else if (v.variable) into.add(term(v.variable));
      break;
    case "minus": case "filter": break; // not in-scope contributors
    }
  }
  return into;
}

/** fresh-name allocator over the whole query's variables (?v -> ?v_1) */
function freshener(allVars) {
  const made = new Map();
  return name => {
    if (made.has(name)) return made.get(name);
    let n = 1;
    while (allVars.has("?" + name + "_" + n)) ++n;
    const f = "?" + name + "_" + n;
    allVars.add(f);
    made.set(name, f);
    return f;
  };
}

function allQueryVars(node, into = new Set()) {
  if (!node || typeof node !== "object") return into;
  if (node.termType === "Variable") into.add("?" + node.value);
  for (const v of Object.values(node))
    if (Array.isArray(v)) v.forEach(x => allQueryVars(x, into));
    else if (v && typeof v === "object") allQueryVars(v, into);
  return into;
}

/* projections + solution modifiers shared by SELECT and subselect */
function collectClause(q, ind) {
  let proj;
  if (q.variables.some(v => v.termType === "Wildcard"))
    proj = "*";
  else
    proj = q.variables.map(v =>
      v.termType === "Variable" ? term(v)
      : "(" + expr(v.expression) + " as " + term(v.variable) + ")").join(" ");
  let s = "collect " + (q.distinct ? "distinct " : "") + "(" + proj + ")";
  if (q.group?.length)
    s += "\n" + ind + "  by (" + q.group.map(g => {
      if (g.expression?.termType === "Variable") return term(g.expression);
      throw new Error("unsupported: GROUP BY expression (use a BIND first)");
    }).join(" ") + ")";
  if (q.order?.length)
    s += "\n" + ind + "  order by " + q.order.map(o => {
      const e = o.expression.termType ? term(o.expression) : "(" + expr(o.expression) + ")";
      return o.descending ? "desc(" + (o.expression.termType ? term(o.expression) : expr(o.expression)) + ")"
           : o.expression.termType ? e : "asc(" + expr(o.expression) + ")";
    }).join(" ");
  if (q.limit != null)  s += " limit "  + q.limit;
  if (q.offset != null) s += " offset " + q.offset;
  const having = (q.having ?? []).map(h => "{" + expr(h) + "}");
  return { collect: s, having };
}

/** a nested SELECT becomes a scoped sub-pipeline sharing its projection */
function subselect(q, ind, ctx = { mode: "topdown" }) {
  if (q.queryType !== "SELECT") throw new Error("unsupported nested query: " + q.queryType);
  const inner = ind + "        ";
  const shared = q.variables.some(v => v.termType === "Wildcard")
    ? [...collectVars(q.where)]
    : q.variables.map(v => v.termType === "Variable" ? term(v) : term(v.variable));
  const { collect, having } = collectClause(q, inner);
  const sctx = { ...ctx, inScope: new Set() }; // subselect isolates
  let body = "ask ( " + group(q.where, inner, sctx) + " )\n" + inner + collect;
  for (const h of having) body += "\n" + inner + h;
  return "scope ( " + body + "\n" + ind + "      ) share (" + shared.join(" ") + ")";
}

function collectVars(patterns, into = new Set()) {
  for (const p of patterns ?? []) {
    for (const t of p.triples ?? [])
      for (const k of ["subject", "predicate", "object"])
        if (t[k].termType === "Variable") into.add("?" + t[k].value);
    for (const key of ["patterns"])
      if (p[key]) collectVars(p[key], into);
    if (p.type === "values")
      for (const v of Object.keys(p.values[0] ?? {})) into.add(v);
    if (p.type === "bind") into.add("?" + p.variable.value);
    if (p.type === "query" && p.variables)
      for (const v of p.variables)
        if (v.termType === "Variable") into.add("?" + v.value);
        else if (v.variable) into.add("?" + v.variable.value);
  }
  return into;
}

/* ── whole queries ──────────────────────────────────────────────────────── */

export function compile(ast, opts = {}) {
  const mode = opts.mode === "bottomup" ? "bottomup" : "topdown";
  const ctx = { mode, inScope: new Set(),
                fresh: freshener(allQueryVars(ast)) };
  const out = [];
  if (mode === "bottomup") {
    out.push("# compiled from SPARQL (sparql-to-algae3.md section 4, bottom-up:");
    out.push("#  groups scoped to their in-scope variables; out-of-scope");
    out.push("#  expression variables renamed apart; OPTIONAL-immediate");
    out.push("#  filters absorbed at the LeftJoin)");
    out.push("require <http://www.w3.org/ns/algae3#eval-bottomup>");
  } else {
    out.push("# compiled from SPARQL (sparql-to-algae3.md section 3, top-down)");
    out.push("require <http://www.w3.org/ns/algae3#eval-topdown>");
  }
  for (const [pfx, iri] of Object.entries(ast.prefixes ?? {}))
    out.push("prefix " + pfx + ": <" + iri + ">");
  if (ast.base) out.push("base <" + ast.base + ">");
  for (const g of ast.from?.default ?? []) out.push("load " + term(g));
  for (const g of ast.from?.named ?? [])   out.push("load " + term(g) + " as " + term(g));
  out.push("");

  const ind = "      ";
  switch (ast.queryType) {
  case "SELECT": {
    const { collect, having } = collectClause(ast, "");
    out.push("ask ( " + group(ast.where, ind, ctx) + " )");
    out.push(collect);
    for (const h of having) out.push(h);
    break;
  }
  case "ASK":
    out.push("test ( " + group(ast.where, ind, ctx) + " )");
    break;
  case "CONSTRUCT":
    out.push("ask ( " + group(ast.where, ind, ctx) + " )");
    out.push("assert ( " + bgp(ast.template ?? [], ind) + " )");
    break;
  default:
    throw new Error("unsupported query form: " + ast.queryType);
  }
  return out.join("\n") + "\n";
}

/** parse text with a sparqljs Parser instance and compile */
export function compileText(sparqlText, SparqlParser, baseIRI, opts) {
  const parser = new SparqlParser(baseIRI ? { baseIRI } : {});
  return compile(parser.parse(sparqlText), opts ?? {});
}
