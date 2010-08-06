SELECT patient.id AS patient, patient.DateOfBirth AS dob, _sex_0_sexEntry.EntryName AS sex, _person2drug_0_itemMed.EntryName AS takes, _person2drug_0_itemMed.PerformedDTTM AS indicDate
       FROM Person AS patient
            INNER JOIN Sex_DE AS _sex_0_sexEntry ON _sex_0_sexEntry.id=patient.SexDE
            INNER JOIN Item_Medication AS _person2drug_0_itemMed ON _person2drug_0_itemMed.PatientID=patient.id
            INNER JOIN Medication AS _person2drug_0_medication ON _person2drug_0_medication.ItemID=_person2drug_0_itemMed.id
            INNER JOIN Medication_DE AS _person2drug_0_medDE ON _person2drug_0_medDE.id=_person2drug_0_medication.MedDictDE
            INNER JOIN NDCcodes AS _person2drug_0_medCodes ON _person2drug_0_medCodes.NDC=_person2drug_0_medDE.NDC
            LEFT OUTER JOIN (
SELECT _person2drug_1_itemMed.PerformedDTTM AS indicDate, _person2drug_1_itemMed.PatientID AS patient, _person2drug_1_medCodes.ingredient AS contraCode
       FROM Item_Medication AS _person2drug_1_itemMed
            INNER JOIN Medication AS _person2drug_1_medication ON _person2drug_1_medication.ItemID=_person2drug_1_itemMed.id
            INNER JOIN Medication_DE AS _person2drug_1_medDE ON _person2drug_1_medDE.id=_person2drug_1_medication.MedDictDE
            INNER JOIN NDCcodes AS _person2drug_1_medCodes ON _person2drug_1_medCodes.NDC=_person2drug_1_medDE.NDC
 WHERE (_person2drug_1_medCodes.ingredient = 11289 OR _person2drug_1_medCodes.ingredient = 11290)
             ) AS opt1 ON opt1.indicDate=_person2drug_0_itemMed.PerformedDTTM AND opt1.patient=patient.id
 WHERE (_person2drug_0_medCodes.ingredient = 6809 OR _person2drug_0_medCodes.ingredient = 6810) AND !(opt1.contraCode IS NOT NULL)
 LIMIT 30
