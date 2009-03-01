# q1.sql — http://www4.wiwiss.fu-berlin.de/bizer/BerlinSPARQLBenchmark/spec/index.html#queryTripleQ1
# $Id: q1.sql,v 1.1 2008-11-16 14:06:36 eric Exp $
# 
# substitutions:
#   @ProductType@=59
#   @ProductFeature1@=5
#   @ProductFeature2@=7
#   @x@=578

SELECT distinct nr, label
FROM product AS p
     INNER JOIN producttypeproduct AS ptp ON p.nr = ptp.product AND ptp.productType=59
     INNER JOIN productfeatureproduct AS pf5 ON pf5.product=p.nr AND pf5.productFeature=5
     INNER JOIN productfeatureproduct AS pf7 ON pf7.product=p.nr AND pf7.productFeature=7
WHERE propertyNum1 > 578
ORDER BY label
LIMIT 10;
