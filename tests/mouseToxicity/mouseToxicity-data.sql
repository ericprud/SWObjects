-- mouseToxicity-data.sql -- Create a set of toxicity
--	associations. These databases are organized
--	as they are in research institutions.  This
--	demonstrates RDF as a language for federating
--	queries across organizationally autonomous
--	databases.

-- $Id: mouseToxicity-data.sql,v 1.6 2004/10/07 01:04:21 eric Exp $

-- CREATING THE TABLES:
-- MySQL invocation:
--   mysql -u root ToxicAssoc < makeToxicAssoc.sql
-- If you want a heterogeneous database, add this command:
--   mysql -u root rdf < makeGenericTripleStore.sql

-- You should see the output:
--   name	chemical	motif	pathway	upname	kd50	chemical	toxicity
--   rq23	lhrh-agonist	@@motif@@	apoptosis	?saProt2	0.8	lhrh-agonist	0.6
--   rq23	lhrh-agonist	@@motif@@	apoptosis	?saProt2	0.8	like1	0.7
-- when you run the last of these commands.

-- ADMINISTRATION:
-- These are some handy code snipets to paste into a command line:
--   Drop all the databases so you can create them again:
--     DROP DATABASE MicroArray;DROP DATABASE Uniprot;DROP DATABASE ScreeningAssay;DROP DATABASE ChemStructure;DROP DATABASE MouseToxicity;DROP DATABASE ToxicAssoc
--   Create a single database (ToxicAssoc) with all the other tables in it.
--      cat makeToxicAssoc.sql | perl -pe "s/-- %\\n/--/g;s/--\\\\\\$//g" |  | mysql -u root ToxicAssoc

-- Now the data:

-- %
CREATE DATABASE MicroArray;
-- %
USE MicroArray;
CREATE TABLE Chemicals (id INT NOT NULL, 
			chemical CHAR(80), 
		        PRIMARY KEY (id));
CREATE TABLE Kinase (id INT NOT NULL, 
		     against INT NOT NULL, 
		     PRIMARY KEY (id));
CREATE TABLE MicroArray (id INT NOT NULL, 
			 name CHAR(80), 
			 expression ENUM("up", "down"), 
			 experiment INT NOT NULL, 
			 PRIMARY KEY (id), 
			 UNIQUE KEY u_name(name));
INSERT INTO Chemicals (id, chemical) VALUES (1001, "lhrh-agonist");
INSERT INTO Kinase (id, against) VALUES (2001, 1001);
INSERT INTO MicroArray (id, name, expression, experiment) VALUES (3001, "rq23", "up", 2001);

-- %
CREATE DATABASE Uniprot;
-- %
USE Uniprot;
CREATE TABLE Uniprot (id INT NOT NULL, 
		      name CHAR(80), 
		      motif CHAR(80), 
		      pathway CHAR(80), 
		      PRIMARY KEY (id), 
		      UNIQUE KEY u_name_motif(name, motif));
INSERT INTO Uniprot (id, name, motif, pathway) VALUES (4001, "rq23", "@@motif@@", "apoptosis");

-- %
CREATE DATABASE ScreeningAssay;
-- %
USE ScreeningAssay;
CREATE TABLE ScreeningAssay (id INT NOT NULL, 
			     name CHAR(80), 
			     chemical CHAR(80), 
			     upname CHAR(80), 
			     kd50 FLOAT, 
			     PRIMARY KEY (id), 
			     UNIQUE KEY u_name_chemical_upname(name, chemical, upname));
INSERT INTO ScreeningAssay (id, name, chemical, upname, kd50) VALUES (5001, "KinaseAssay", "lhrh-agonist", "?saProt1", .6);
INSERT INTO ScreeningAssay (id, name, chemical, upname, kd50) VALUES (5002, "KinaseAssay", "lhrh-agonist", "?saProt2", .8);
INSERT INTO ScreeningAssay (id, name, chemical, upname, kd50) VALUES (5003, "KinaseAssay", "lhrh-agonist", "?saProt3", .1);

-- %
CREATE DATABASE ChemStructure;
-- %
USE ChemStructure;
CREATE TABLE ChemStructure (id INT NOT NULL, 
			    chemical CHAR(80), 
			    structure CHAR(80), 
			    sidechain CHAR(20), 
			    PRIMARY KEY (id), 
			    UNIQUE KEY u_chemical_sidechain(chemical, sidechain));
INSERT INTO ChemStructure (id, chemical, structure, sidechain) VALUES (6001, "lhrh-agonist", "asdfasdf", "sc1");
INSERT INTO ChemStructure (id, chemical, structure, sidechain) VALUES (6002, "dummy0", "asdfasdf", "sc0");
INSERT INTO ChemStructure (id, chemical, structure, sidechain) VALUES (6003, "like1", "asdfasdf", "sc1");
INSERT INTO ChemStructure (id, chemical, structure, sidechain) VALUES (6004, "like2", "asdfasdf", "sc1");
INSERT INTO ChemStructure (id, chemical, structure, sidechain) VALUES (6005, "dummy3", "asdfasdf", "sc2");

-- %
CREATE DATABASE MouseToxicity;
-- %
USE MouseToxicity;
CREATE TABLE MouseToxicity (id INT NOT NULL, 
			    chemical CHAR(80), 
			    toxicity FLOAT, 
			    PRIMARY KEY (id), 
			    UNIQUE KEY u_chemical(chemical));
INSERT INTO MouseToxicity (id, chemical, toxicity) VALUES (7001, "lhrh-agonist", .6);
INSERT INTO MouseToxicity (id, chemical, toxicity) VALUES (7002, "dummy0", .6);
INSERT INTO MouseToxicity (id, chemical, toxicity) VALUES (7003, "like1", .7);
INSERT INTO MouseToxicity (id, chemical, toxicity) VALUES (7004, "like2", .3);
INSERT INTO MouseToxicity (id, chemical, toxicity) VALUES (7005, "dummy3", .3);
-- Test inserted data


-- $
-- $ SELECT MicroArray.name, Chemicals.chemical, Uniprot.motif, Uniprot.pathway, ScreeningAssay.upname, ScreeningAssay.kd50, likeChem.chemical, MouseToxicity.toxicity
-- $   FROM MicroArray
-- $        INNER JOIN Kinase ON Kinase.id=MicroArray.experiment
-- $        INNER JOIN Chemicals ON Chemicals.id=Kinase.against
-- $        INNER JOIN Uniprot ON Uniprot.name=MicroArray.name
-- $        INNER JOIN ScreeningAssay ON ScreeningAssay.chemical=Chemicals.chemical
-- $        INNER JOIN ChemStructure ON ChemStructure.chemical=Chemicals.chemical
-- $        INNER JOIN ChemStructure AS likeChem ON likeChem.sidechain=ChemStructure.sidechain
-- $        INNER JOIN MouseToxicity ON MouseToxicity.chemical=likeChem.chemical
-- $  WHERE MicroArray.expression="up"
-- $    AND ScreeningAssay.kd50 >= .7
-- $    AND MouseToxicity.toxicity > .5;

-- Expected results from above query:
-- name	chemical	motif	pathway	upname	kd50	chemical	toxicity
-- rq23	lhrh-agonist	@@motif@@	apoptosis	?saProt2	0.8	lhrh-agonist	0.6
-- rq23	lhrh-agonist	@@motif@@	apoptosis	?saProt2	0.8	like1	0.7

-- or with lines:
-- +------+--------------+-----------+-----------+----------+------+--------------+----------+
-- | name | chemical     | motif     | pathway   | upname   | kd50 | chemical     | toxicity |
-- +------+--------------+-----------+-----------+----------+------+--------------+----------+
-- | rq23 | lhrh-agonist | @@motif@@ | apoptosis | ?saProt2 |  0.8 | lhrh-agonist |      0.6 |
-- | rq23 | lhrh-agonist | @@motif@@ | apoptosis | ?saProt2 |  0.8 | like1        |      0.7 |
-- +------+--------------+-----------+-----------+----------+------+--------------+----------+

