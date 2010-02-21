<?xml-stylesheet href="http://www.w3.org/StyleSheets/base.css" type="text/css"?>
<?xml-stylesheet href="http://www.w3.org/2002/02/style-xsl.css" type="text/css"?>
<xsl:stylesheet 
  xmlns:foaf="http://xmlns.com/foaf/0.1/"
    xmlns:xsl  ="http://www.w3.org/1999/XSL/Transform" version="1.0"
    xmlns:html    ="http://www.w3.org/1999/xhtml"
    xmlns:rdf  ="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
    xmlns:foafGrddl ="http://www.w3.org/2003/12/rdf-in-xhtml-xslts/grokFOAF"
    >

<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
      <title>Stylesheet to extract FOAF info from XHTML documents</title>
      <link rel="stylesheet" href="http://www.w3.org/StyleSheets/base"/>
    </head>
    <body>
      <div class='head'><a href="/"><img src='/Icons/w3c_home' alt='W3C'/></a></div>
      <h1>Stylesheet to extract FOAF info from XHTML documents</h1>
<p>This transformation produces FOAF data
from XHTML, per <a
href="http://www.w3.org/2003/11/rdf-in-xhtml-proposal">RDF in XHTML
proposal</a>. (see also:
<a href="http://www.w3.org/2003/11/rdf-in-xhtml-demo">demo</a>.), with the following conventions:
</p>
<ul>
  <li>each data for a Person is contained in an element with a <code>class</code> set to <code>foaf-person</code></li>
  <li>the name of the person is the content of the element with a <code>class</code> set to <code>foaf-name</code>, possibly detailed with sub-elements with <code>class</code> set to <code>foaf-family</code> and <code>foaf-given</code></li>
  <li>an <code>image</code> element with a <code>class</code> set to <code>foaf-depiction</code> refers to a picture of the person</li>
  <li>any <code>mailto:</code> link in this element is associated with as a mailbox of the person</li>
  <li>any <code>tel:</code> link in this element is associated with as a phone number for  the person</li>
  <li>the homepage of the work place is identified with a link qualified with a <code>rel</code> attribute set to <code>foaf-work</code></li>
  <li>the homepage of the person is identified with a link qualified with a <code>rel</code> attribute set to <code>foaf-home</code></li>
  <li>known people are identified with links to their homepage or their mailbox, with a <code>rel</code> set to <code>foaf-knows</code></li>
</ul>
<p>This is purely experimental, and has not been reviewed (and even less endorsed) by anybody involved in the <a href="http://www.foaf-project.org/">FOAF project</a>.</p>
<p>If you want to extend this style sheet to support additional properties embedded in the mark up structure as described above, this style sheet has an extensibility point in so that it calls a <code>foafGrddl:extend</code> template in each <code>foaf:Person</code> it creates; by importing this style sheet and overriding the <code>foafGrddl:extend</code> template, you can scrape new properties. (<code>foafGrddl</code> is linked to <code>http://www.w3.org/2003/12/rdf-in-xhtml-xslts/grokFOAF</code>)</p>

<address>
<a href="http://www.w3.org/People/Connolly/">Dan Connolly</a>  and <a href="/People/Dom/">Dominique Haza&#xeb;l-Massieux</a><br />
<small>$Id: grokFOAF.xsl,v 1.15 2005/09/21 13:33:25 dom Exp $</small>
</address>
</body>
</html>

<xsl:template match="/">
  <rdf:RDF>
    <xsl:for-each select="/html:html/html:body//html:*[contains(@class,'foaf-person')]">
      <foaf:Person>
        <xsl:if test="descendant::html:*[contains(@class,'foaf-name')]">
          <foaf:name><xsl:value-of select="descendant::html:*[contains(@class,'foaf-name')]"/></foaf:name>
          <xsl:if test="descendant::html:*[contains(@class,'foaf-family')]">
            <foaf:family_name><xsl:value-of select="descendant::html:*[contains(@class,'foaf-family')]"/></foaf:family_name>
          </xsl:if>
          <xsl:if test="descendant::html:*[contains(@class,'foaf-given')]">
            <foaf:givenname><xsl:value-of select="descendant::html:*[contains(@class,'foaf-given')]"/></foaf:givenname>
          </xsl:if>
        </xsl:if>
        <xsl:for-each select="descendant::html:img[contains(@class,'foaf-depiction')]">
          <foaf:depiction rdf:resource="{@src}"/>
        </xsl:for-each>
        <xsl:for-each select="descendant::html:a[starts-with(@href,'mailto:') and not(contains(@rel,'foaf-knows'))]">
          <foaf:mbox rdf:resource="{@href}"/>
        </xsl:for-each>
        <xsl:for-each select="descendant::html:a[starts-with(@href,'tel:') and not(contains(@rel,'foaf-knows'))]">
          <foaf:phone rdf:resource="{@href}"/>
        </xsl:for-each>
        <xsl:for-each select="descendant::html:a[contains(@rel,'foaf-work')]">
          <foaf:workplaceHomepage rdf:resource="{@href}" />
        </xsl:for-each>
        <xsl:for-each select="descendant::html:a[contains(@rel,'foaf-home')]">
          <foaf:homepage rdf:resource="{@href}" />
        </xsl:for-each>
        <xsl:for-each select="descendant::html:a[contains(@rel,'foaf-knows')]">
          <foaf:knows>
            <foaf:Person>
              <foaf:name><xsl:value-of select="."/></foaf:name>
              <xsl:choose>
                <xsl:when test="starts-with(@href,'mailto:')">
                  <foaf:mbox rdf:resource="{@href}"/>
                </xsl:when>
                <xsl:otherwise>
                  <foaf:homepage rdf:resource="{@href}"/>
                </xsl:otherwise>
              </xsl:choose>
            </foaf:Person>
          </foaf:knows>
        </xsl:for-each>
        <xsl:call-template name="foafGrddl:extend"/>
      </foaf:Person>
    </xsl:for-each>
  </rdf:RDF>
</xsl:template>

<xsl:template name="foafGrddl:extend"/>
</xsl:stylesheet>
