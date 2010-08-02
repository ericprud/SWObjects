SELECT patient.id AS patient, patient.DateOfBirth AS dob, sexEntry_gen0.EntryName AS sex, indicItem_gen2.EntryName AS takes, indicItem_gen2.PerformedDTTM AS indicDate
       FROM Person AS patient
            INNER JOIN Sex_DE AS sexEntry_gen0 ON sexEntry_gen0.id=patient.SexDE
            INNER JOIN Item_Medication AS indicItem_gen2 ON indicItem_gen2.PatientID=patient.id
            INNER JOIN Medication AS indicMed_gen3 ON indicMed_gen3.ItemID=indicItem_gen2.id
            INNER JOIN Medication_DE AS indicDE_gen5 ON indicDE_gen5.id=indicMed_gen3.MedDictDE
            INNER JOIN NDCcodes AS indicCode_gen1 ON indicCode_gen1.NDC=indicDE_gen5.NDC
            LEFT OUTER JOIN (
    SELECT indicItem_gen3.PerformedDTTM AS indicDate, indicItem_gen3.PatientID AS patient, indicCode_gen2.ingredient AS contCode
           FROM Item_Medication AS indicItem_gen3
                INNER JOIN Medication AS indicMed_gen4 ON indicMed_gen4.ItemID=indicItem_gen3.id
                INNER JOIN Medication_DE AS indicDE_gen6 ON indicDE_gen6.id=indicMed_gen4.MedDictDE
                INNER JOIN NDCcodes AS indicCode_gen2 ON indicCode_gen2.NDC=indicDE_gen6.NDC
     WHERE (indicCode_gen2.ingredient = 11289 OR indicCode_gen2.ingredient = 11290)
             ) AS opt1 ON opt1.indicDate=indicItem_gen2.PerformedDTTM AND opt1.patient=patient.id
 WHERE (indicCode_gen1.ingredient = 6809 OR indicCode_gen1.ingredient = 6810) AND !(opt1.contCode IS NOT NULL)
 LIMIT 30;
