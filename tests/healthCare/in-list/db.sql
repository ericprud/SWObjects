SELECT patient.id AS patient, patient.DateOfBirth AS dob, sexEntry_gen1.EntryName AS sex, indicItem_gen2.EntryName AS takes, indicItem_gen2.PerformedDTTM AS indicDate
       FROM Person AS patient
            INNER JOIN Sex_DE AS sexEntry_gen1 ON sexEntry_gen1.id=patient.SexDE
            INNER JOIN Item_Medication AS indicItem_gen2 ON indicItem_gen2.PatientID=patient.id
            INNER JOIN Medication AS indicMed_gen5 ON indicMed_gen5.ItemID=indicItem_gen2.id
            INNER JOIN Medication_DE AS indicDE_gen4 ON indicDE_gen4.id=indicMed_gen5.MedDictDE
            INNER JOIN NDCcodes AS indicCode_gen0 ON indicCode_gen0.NDC=indicDE_gen4.NDC
 WHERE (indicCode_gen0.ingredient = 6809 OR indicCode_gen0.ingredient = 6810)
 LIMIT 30
