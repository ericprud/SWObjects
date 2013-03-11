
INSERT {
   GRAPH <g1> { ?s a <Foo> }
} WHERE {
  { ?s <p> ?o }
  OPTIONAL { ?s2 <p> ?o2 FILTER (?o < ?o2)}
  FILTER (!BOUND(?s2))
}
