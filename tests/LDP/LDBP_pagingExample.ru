PREFIX ldp: <https://github.com/ericprud/SWObjects/wiki/Sparql-extensions#>
PREFIX container: <http://example.org/netWorth/nw1/assetContainer>
PREFIX page: <http://example.org/netWorth/nw1/assetContainer?p=>
PREFIX membership: <http://example.org/netWorth/nw1>
PREFIX asset: <http://example.org/netWorth/nw1/assetContainer/>
PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
PREFIX dcterms: <http://purl.org/dc/terms/>
PREFIX bp: <http://open-services.net/ns/basicProfile#>
PREFIX o: <http://example.org/ontology/>
PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>
DELETE    { GRAPH ?LastTail { ?LastTail bp:nextPage ?NewNil } }
INSERT    {
  GRAPH ?LastTail { ?LastTail bp:nextPage ?NewTail }
  GRAPH ?NewTail {
    container: a bp:Container ;
        dcterms:title "The assets of JohnZSmith" ;
        bp:membershipSubject membership: ;
        bp:membershipPredicate o:asset .
      ?NewTail a bp:Page ; bp:pageOf container: .
  }
  GRAPH ?CurTail {
      ?CurTail bp:nextPage rdf:nil .
      membership: a o:NetWorth ; o:asset ?NewObj .
      ?NewObj a ?type ; dcterms:title ?title ; o:value ?value
  }
  GRAPH ?NewObj { ?NewObj a ?type ; dcterms:title ?title ; o:value ?value ; dcterms:date ?date }
}
CONSTRUCT { ?NewObj a ?type }
WHERE     {
  ?oldObj a ?type ; dcterms:title ?title ; o:value ?value ; dcterms:date ?date
  BIND (ldp:lastTail(container:, membership:, o:asset, 4) AS ?LastTail)
  BIND (ldp:newTail (container:, membership:, o:asset, 4) AS ?NewTail)
  BIND (ldp:newNil  (container:, membership:, o:asset, 4) AS ?NewNil)
  BIND (ldp:curTail (container:, membership:, o:asset, 4) AS ?CurTail)
  BIND (ldp:newObj  (asset:a) AS ?NewObj)
}
