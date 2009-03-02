# q3.sql — http://www4.wiwiss.fu-berlin.de/bizer/BerlinSPARQLBenchmark/spec/index.html#queryTripleQ3
# $Id: q3.sql,v 1.1 2008-11-16 14:06:36 eric Exp $
# 
# substitutions:
#   @ProductType@=59
#   @ProductFeature1@=5
#   @ProductFeature2@=7
#   @x@=66
#   @y@=84

SELECT p.nr, p.label
FROM product AS p
     INNER JOIN producttypeproduct AS ptp ON p.nr=ptp.product
     INNER JOIN productfeatureproduct AS pfp5 ON pfp5.product=p.nr AND pfp5.productFeature=5
     LEFT OUTER JOIN productfeatureproduct AS pfp7 ON pfp7.product=p.nr AND pfp7.productFeature=7
WHERE productType=59
	AND propertyNum1>66
	AND propertyNum3<84
	AND pfp7.product IS NULL
ORDER BY p.label
LIMIT 10;
