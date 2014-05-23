BOOST_AUTO_TEST_CASE( tsv01 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/sparql11-test-suite/csv-tsv-res/manifest#tsv01";
    // name: tsv01 - TSV Result Format
    // manifest: sparql11-test-suite/csv-tsv-res/manifest.ttl
    const char* defaultGraph_in = "sparql11-test-suite/csv-tsv-res/data.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "sparql11-test-suite/csv-tsv-res/csvtsv01.rq";
    const char* result = "sparql11-test-suite/csv-tsv-res/csvtsv01.tsv";
    QUERY_TEST();
} /* BOOST_AUTO_TEST_CASE( tsv01 ) */
BOOST_AUTO_TEST_CASE( tsv02 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/sparql11-test-suite/csv-tsv-res/manifest#tsv02";
    // name: tvs02 - TSV Result Format
    // manifest: sparql11-test-suite/csv-tsv-res/manifest.ttl
    const char* defaultGraph_in = "sparql11-test-suite/csv-tsv-res/data.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "sparql11-test-suite/csv-tsv-res/csvtsv02.rq";
    const char* result = "sparql11-test-suite/csv-tsv-res/csvtsv02.tsv";
    QUERY_TEST();
} /* BOOST_AUTO_TEST_CASE( tsv02 ) */
BOOST_AUTO_TEST_CASE( tsv03 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/sparql11-test-suite/csv-tsv-res/manifest#tsv03";
    // name: tsv03 - TSV Result Format
    // manifest: sparql11-test-suite/csv-tsv-res/manifest.ttl
    const char* defaultGraph_in = "sparql11-test-suite/csv-tsv-res/data2.ttl";
    LabeledGraph namedGraphs_in[] = {};
    const char* request = "sparql11-test-suite/csv-tsv-res/csvtsv01.rq";
    const char* result = "sparql11-test-suite/csv-tsv-res/csvtsv03.tsv";
    QUERY_TEST();
} /* BOOST_AUTO_TEST_CASE( tsv03 ) */
