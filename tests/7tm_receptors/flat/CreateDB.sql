/* CreateDB.sql - scoop csv files from <http://www.w3.org/2008/04/DiabeticPatientsDataSet/> into an SQL DB.
 * $Id: CreateDB.sql,v 1.9 2008/09/30 11:24:43 eric Exp $
 *
 * BUGS:
 *   empty fields (i.e. ",,") map to 0's in INT fields. hoped for NULL.
 */

CREATE TABLE receptors (ID TINYINT PRIMARY KEY NOT NULL AUTO_INCREMENT, Family VARCHAR(40) NOT NULL, Code VARCHAR(25), Ligand VARCHAR(13), Official_IUPHAR_name VARCHAR(20) NOT NULL, 
    Human_gene_name VARCHAR(10),                     HGNC_ID INT, Human_genetic_localisation VARCHAR(15), Human_nucleotide_RefSeq VARCHAR(15), Human_protein_RefSeq VARCHAR(15), Human_SwissProt VARCHAR(10), Human_Entrez_Gene VARCHAR(10),
      Rat_gene_name VARCHAR(10),      Rat_Genome_Database_ID INT,   Rat_genetic_localisation VARCHAR(15),   Rat_nucleotide_RefSeq VARCHAR(15),   Rat_protein_RefSeq VARCHAR(15),   Rat_SwissProt VARCHAR(10),   Rat_Entrez_Gene VARCHAR(10),
    Mouse_gene_name VARCHAR(10), Mouse_Genome_Informatics_ID INT, Mouse_genetic_localisation VARCHAR(15), Mouse_nucleotide_RefSeq VARCHAR(15), Mouse_protein_RefSeq VARCHAR(15), Mouse_SwissProt VARCHAR(10), Mouse_Entrez_Gene VARCHAR(10))
       ENGINE = INNODB;
LOAD DATA LOCAL INFILE '../IUPHAR_Receptors_ClassC.csv'
            INTO TABLE receptors
            FIELDS TERMINATED BY ',' ENCLOSED BY '' LINES TERMINATED BY '\r\n' IGNORE 1 LINES
            (Family, Code, Ligand, Official_IUPHAR_name, 
		Human_gene_name,                     HGNC_ID, Human_genetic_localisation, Human_nucleotide_RefSeq, Human_protein_RefSeq, Human_SwissProt, Human_Entrez_Gene,
		  Rat_gene_name,      Rat_Genome_Database_ID,   Rat_genetic_localisation,   Rat_nucleotide_RefSeq,   Rat_protein_RefSeq,   Rat_SwissProt,   Rat_Entrez_Gene,
		Mouse_gene_name, Mouse_Genome_Informatics_ID, Mouse_genetic_localisation, Mouse_nucleotide_RefSeq, Mouse_protein_RefSeq, Mouse_SwissProt, Mouse_Entrez_Gene)
	    ;
SHOW WARNINGS;
