#!/bin/bash

# Map the qt:endpoints to local servers.
echo -e 'servicemap=s{http://example.org/sparql}{http://102.49.40.12:8881/sparql}' > .sparql.cfg

# Start the local servers.
../bin/sparql -d sparql11-test-suite/service/data04endpoint.ttl --serve http://102.49.40.12:8881/sparql &

# Execute the query, comparing against the expected results.
sleep 1
../bin/sparql -d sparql11-test-suite/service/data04.ttl sparql11-test-suite/service/service04a.rq --compare sparql11-test-suite/service/service04.srx

# Kill off the servers.
kill %1

