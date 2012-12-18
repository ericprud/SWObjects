#!/bin/bash

# Map the qt:endpoints to local servers.
echo -e 'servicemap=s{http://example1.org/sparql}{http://102.49.40.12:8881/sparql}' > .sparql.cfg

# Start the local servers.
../bin/sparql -d data-sparql11/service/data06endpoint1.ttl --serve http://102.49.40.12:8881/sparql &

# Execute the query, comparing against the expected results.
sleep 1
../bin/sparql data-sparql11/service/service06.rq --compare data-sparql11/service/service06.srx

# Kill off the servers.
kill %1

