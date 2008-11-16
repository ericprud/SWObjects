# q2.sql — http://www4.wiwiss.fu-berlin.de/bizer/BerlinSPARQLBenchmark/spec/index.html#queryTripleQ2
# $Id: q2.sql,v 1.1 2008-11-16 14:06:36 eric Exp $
# 
# substitutions:
#   @ProductXYZ@=62

SELECT pt.label, pt.comment, pt.producer, productFeature, propertyTex1, propertyTex2, propertyTex3, 
	propertyNum1, propertyNum2, propertyTex4, propertyTex5, propertyNum4
FROM product AS pt
     INNER JOIN producer AS pr ON pt.producer=pr.nr
     INNER JOIN productfeatureproduct AS pfp ON pt.nr=pfp.product
WHERE pt.nr=62;
