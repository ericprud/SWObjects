// Regenerate the committed compiler fixtures (evidence-dnf.{topdown,bottomup}.a3)
// and verify both evaluate to expected/evidence-dnf.expected.
//   cd tests/Algae3 && npm i --no-save sparqljs && node regen-compiled.mjs
import SparqlJs from "sparqljs";
import { compileText } from "../../sparql-to-a3.js";
import { readFileSync, writeFileSync } from "fs";
import { execFileSync } from "child_process";
const rq = readFileSync("evidence-dnf.rq", "utf8");
let status = 0;
for (const mode of ["topdown", "bottomup"]) {
  const out = `evidence-dnf.${mode}.a3`;
  writeFileSync(out, compileText(rq, SparqlJs.Parser, null, { mode }));
  const got = execFileSync("../../bin/algae3", ["--sorted-bindings", out]).toString();
  const want = readFileSync("expected/evidence-dnf.expected", "utf8");
  console.log(mode + ": " + (got === want ? "MATCH" : (status = 1, "DIFF")));
}
process.exit(status);
