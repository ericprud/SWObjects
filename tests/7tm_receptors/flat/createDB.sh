#!/bin/sh

# This is a script to create a MySQL DB from the .txt files
# in <http://swobjects.svn.sourceforge.net/svnroot/swobjects/trunk/tests/7tm_receptors/flat/> .
# $Id: createDB,v 1.1 2008/07/25 21:33:23 eric Exp $

CREDS='-u root '

mysqladmin $CREDS -f drop 7tm_receptors;
mysqladmin $CREDS create 7tm_receptors;
mysql -u root 7tm_receptors < CreateDB.sql
