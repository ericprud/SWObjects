BOOST_AUTO_TEST_CASE( tsv01 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/csv-tsv-res/manifest#tsv01";
    // name: tsv01 - TSV Result Format
    // manifest: data-sparql11/csv-tsv-res/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/csv-tsv-res/data.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/csv-tsv-res/csvtsv01.rq";
    const char* result = "data-sparql11/csv-tsv-res/csvtsv01.tsv";
    QUERY_TEST();
} /* BOOST_AUTO_TEST_CASE( tsv01 ) */
BOOST_AUTO_TEST_CASE( tsv02 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/csv-tsv-res/manifest#tsv02";
    // name: tvs02 - TSV Result Format
    // manifest: data-sparql11/csv-tsv-res/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/csv-tsv-res/data.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/csv-tsv-res/csvtsv02.rq";
    const char* result = "data-sparql11/csv-tsv-res/csvtsv02.tsv";
    QUERY_TEST();
} /* BOOST_AUTO_TEST_CASE( tsv02 ) */
BOOST_AUTO_TEST_CASE( tsv03 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/csv-tsv-res/manifest#tsv03";
    // name: tsv03 - TSV Result Format
    // manifest: data-sparql11/csv-tsv-res/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/csv-tsv-res/data2.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "data-sparql11/csv-tsv-res/csvtsv01.rq";
    const char* result = "data-sparql11/csv-tsv-res/csvtsv03.tsv";
    QUERY_TEST();
} /* BOOST_AUTO_TEST_CASE( tsv03 ) */
