#!/bin/bash

# Map the qt:endpoints to local servers.
echo -e 'servicemap=s{http://example1.org/sparql}{http://102.49.40.12:8881/sparql}\nservicemap=s{http://example2.org/sparql}{http://102.49.40.12:8882/sparql}' > .sparql.cfg

# Start the local servers
../bin/sparql -d data-sparql11/service/data05endpoint1.ttl --serve http://102.49.40.12:8881/sparql &
../bin/sparql -d data-sparql11/service/data05endpoint2.ttl --serve http://102.49.40.12:8882/sparql &

# Execute the query, comparing against the expected results.
sleep 1
../bin/sparql -d data-sparql11/service/data05.ttl data-sparql11/service/service05.rq --compare data-sparql11/service/service05.srx

# Kill off the servers.
kill %1
kill %2

