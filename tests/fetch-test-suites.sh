#!/bin/sh
# Fetch the W3C test-suite data needed by test_Turtle, test_Trig,
# test_RDFXML and test_SPARQL11. Idempotent: skips suites already present.
# Run from anywhere; data lands next to this script.
set -e
cd "$(dirname "$0")"

if [ ! -d TurtleTests ]; then
    echo "Fetching TurtleTests..."
    curl -sL http://www.w3.org/2013/TurtleTests/TESTS.tar.gz | tar xzf -
fi

if [ ! -d TriGTests ]; then
    echo "Fetching TriGTests..."
    mkdir -p TriGTests
    curl -sL http://www.w3.org/2013/TrigTests/TESTS.tar.gz | tar xzf - -C TriGTests
fi

if [ ! -d RDFXMLTests ]; then
    echo "Fetching RDFXMLTests..."
    mkdir -p RDFXMLTests
    curl -sL http://www.w3.org/2013/RDFXMLTests/TESTS.tar.gz | tar xzf - -C RDFXMLTests
fi

if [ ! -d sparql11-test-suite ]; then
    echo "Fetching sparql11-test-suite..."
    curl -sL http://www.w3.org/2009/sparql/docs/tests/sparql11-test-suite-20121023.tar.gz | tar xzf -
    (cd sparql11-test-suite && patch -p 0 < ../sparql11-test-suite.patch)
fi

echo "Test suites ready."
