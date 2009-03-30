/* CreateDB.sql - scoop csv files from <http://www.w3.org/2008/04/DiabeticPatientsDataSet/> into an SQL DB.
 * $Id: CreateDB.sql,v 1.9 2008/09/30 11:24:43 eric Exp $
 *
 * BUGS:
 *   empty fields (i.e. ",,") map to 0's in INT fields. hoped for NULL.
 */

CREATE TABLE receptors (ID TINYINT PRIMARY KEY NOT NULL AUTO_INCREMENT, Family CHAR(40) NOT NULL, Code CHAR(25), Ligand CHAR(13), Official_IUPHAR_name CHAR(20) NOT NULL, 
    Human_gene_name CHAR(10),                     HGNC_ID INT, Human_genetic_localisation CHAR(15), Human_nucleotide_RefSeq CHAR(15), Human_protein_RefSeq CHAR(15), Human_SwissProt CHAR(10), Human_Entrez_Gene CHAR(10),
      Rat_gene_name CHAR(10),      Rat_Genome_Database_ID INT,   Rat_genetic_localisation CHAR(15),   Rat_nucleotide_RefSeq CHAR(15),   Rat_protein_RefSeq CHAR(15),   Rat_SwissProt CHAR(10),   Rat_Entrez_Gene CHAR(10),
    Mouse_gene_name CHAR(10), Mouse_Genome_Informatics_ID INT, Mouse_genetic_localisation CHAR(15), Mouse_nucleotide_RefSeq CHAR(15), Mouse_protein_RefSeq CHAR(15), Mouse_SwissProt CHAR(10), Mouse_Entrez_Gene CHAR(10))
       ENGINE = INNODB;
LOAD DATA LOCAL INFILE '/home/eric/checkouts/swobjects/trunk/tests/7tm_receptors/IUPHAR_Receptors_ClassC.csv'
            INTO TABLE receptors
            FIELDS TERMINATED BY ',' ENCLOSED BY '' LINES TERMINATED BY '\r\n' IGNORE 1 LINES
            (Family, Code, Ligand, Official_IUPHAR_name, 
		Human_gene_name,                     HGNC_ID, Human_genetic_localisation, Human_nucleotide_RefSeq, Human_protein_RefSeq, Human_SwissProt, Human_Entrez_Gene,
		  Rat_gene_name,      Rat_Genome_Database_ID,   Rat_genetic_localisation,   Rat_nucleotide_RefSeq,   Rat_protein_RefSeq,   Rat_SwissProt,   Rat_Entrez_Gene,
		Mouse_gene_name, Mouse_Genome_Informatics_ID, Mouse_genetic_localisation, Mouse_nucleotide_RefSeq, Mouse_protein_RefSeq, Mouse_SwissProt, Mouse_Entrez_Gene)
	    ;
SHOW WARNINGS;
