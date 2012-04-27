<?xml version="1.0" encoding="utf-8"?>
<!-- $Id: Pat2rdf.xsl,v 1.23 2009/11/30 03:42:28 eric Exp $ -->
<xsl:stylesheet 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:in="http://indivo.org/vocab/xml/documents#"
    xmlns="http://indivo.org/vocab/xml/documents#999"
    version="1.0">

<xsl:output method="text" indent='yes' encoding='utf-8'
	    omit-xml-declaration="yes"	    
	    media-type="text/turtle" version="1.0"/>

<xsl:template match="TestResult">
@prefix doap: &lt;http://usefulinc.com/ns/doap#&gt;.
@prefix earl: &lt;http://www.w3.org/ns/earl#&gt;.
@prefix foaf: &lt;http://xmlns.com/foaf/0.1/&gt;.
@prefix swobj: &lt;http://swobjects.svn.sourceforge.net/#&gt;.
@prefix tests: &lt;http://swobjects.svn.sourceforge.net/viewvc/swobjects/branches/sparql11/tests/&gt;.
@prefix dct: &lt;http://purl.org/dc/terms/&gt;.
@prefix xsd: &lt;http://www.w3.org/2001/XMLSchema#&gt;.
@prefix rdb2rdf: &lt;http://www.w3.org/2001/sw/rdb2rdf/test-cases/#&gt;.

&lt;&gt; foaf:primaryTopic swobj:project ;
	dct:issued "2012-02-11T19:49:20Z"^^xsd:dateTime ;
	foaf:maker &lt;http://www.w3.org/People/Eric/ericP-foaf#ericP&gt; .

swobj:project
	a doap:Project ;
	doap:name "SWObjects dm-materialize" ;
	doap:homepage &lt;http://swobjects.svn.sourceforge.net/&gt; .

&lt;http://www.w3.org/People/Eric/ericP-foaf#ericP&gt; a foaf:Person ;
	foaf:name "Eric Prud'hommeaux" ;
	foaf:mbox &lt;mailto:eric@w3.org&gt; ;
	foaf:homepage &lt;http://www.w3.org/People/Eric/&gt; .

tests:test_DM.cpp
	a earl:Software ;
	dct:title "SWObjects dm-materialize test harness" ;
	foaf:maker &lt;http://www.w3.org/People/Eric/ericP-foaf#ericP&gt; .


  <xsl:apply-templates select="TestSuite/TestSuite/TestCase"/>
</xsl:template>

<xsl:template match="TestCase">
[] a earl:Assertion;
	earl:assertedBy tests:test_DM.cpp ;
	earl:result [
		a earl:TestResult ;
		earl:outcome earl:<xsl:value-of select="@result"/>
	] ;
	earl:subject swobj:project ;
	earl:test rdb2rdf:<xsl:value-of select="../@name"/> ;
	earl:info "<xsl:value-of select="@name"/>" .
</xsl:template>


</xsl:stylesheet>
