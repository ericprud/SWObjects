BOOST_AUTO_TEST_CASE( service1 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service1";
    // name: SERVICE test 1
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/service/data01.ttl";
    LabeledGraph services[] = {LG("data-sparql11/service/data01endpoint.ttl", "http://example.org/sparql")};
    const char* request = "data-sparql11/service/service01.rq";
    const char* results = "data-sparql11/service/service01.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service1 ) */
BOOST_AUTO_TEST_CASE( service2 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service2";
    // name: SERVICE test 2
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph services[] = {LG("data-sparql11/service/data02endpoint1.ttl", "http://example1.org/sparql"), LG("data-sparql11/service/data02endpoint2.ttl", "http://example2.org/sparql")};
    const char* request = "data-sparql11/service/service02.rq";
    const char* results = "data-sparql11/service/service02.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service2 ) */

#if FIXED_TEST_HARNESS
BOOST_AUTO_TEST_CASE( service3 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service3";
    // name: SERVICE test 3
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph services[] = {LG("data-sparql11/service/data03endpoint1.ttl", "http://example1.org/sparql"), LG("data-sparql11/service/data03endpoint2.ttl", "http://example2.org/sparql")};
    const char* request = "data-sparql11/service/service03.rq";
    const char* results = "data-sparql11/service/service03.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service3 ) */
BOOST_AUTO_TEST_CASE( service4a ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service4a";
    // name: SERVICE test 4a with VALUES clause
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/service/data04.ttl";
    LabeledGraph services[] = {LG("data-sparql11/service/data04endpoint.ttl", "http://example.org/sparql")};
    const char* request = "data-sparql11/service/service04a.rq";
    const char* results = "data-sparql11/service/service04.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service4a ) */
BOOST_AUTO_TEST_CASE( service5 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service5";
    // name: SERVICE test 5
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/service/data05.ttl";
    LabeledGraph services[] = {LG("data-sparql11/service/data05endpoint1.ttl", "http://example1.org/sparql"), LG("data-sparql11/service/data05endpoint2.ttl", "http://example2.org/sparql")};
    const char* request = "data-sparql11/service/service05.rq";
    const char* results = "data-sparql11/service/service05.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service5 ) */
BOOST_AUTO_TEST_CASE( service6 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service6";
    // name: SERVICE test 6
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = NULL;
    LabeledGraph services[] = {LG("data-sparql11/service/data06endpoint1.ttl", "http://example1.org/sparql")};
    const char* request = "data-sparql11/service/service06.rq";
    const char* results = "data-sparql11/service/service06.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service6 ) */
#endif // FIXED_TEST_HARNESS

BOOST_AUTO_TEST_CASE( service7 ) {
    const char* test = "http://www.w3.org/2009/sparql/docs/tests/data-sparql11/service/manifest#service7";
    // name: SERVICE test 7
    // manifest: data-sparql11/service/manifest.ttl
    const char* defaultGraph_in = "data-sparql11/service/data07.ttl";
    LabeledGraph services[] = {};
    const char* request = "data-sparql11/service/service07.rq";
    const char* results = "data-sparql11/service/service07.srx";
    SERVICE_TEST();
} /* BOOST_AUTO_TEST_CASE( service7 ) */
