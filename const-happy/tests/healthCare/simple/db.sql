SELECT patient.id AS patient, patient.DateOfBirth AS dob, sexEntry_gen2.EntryName AS sex, indicItem_gen4.EntryName AS takes, indicItem_gen4.PerformedDTTM AS indicDate
       FROM Person AS patient
            INNER JOIN Sex_DE AS sexEntry_gen2 ON sexEntry_gen2.id=patient.SexDE
            INNER JOIN Item_Medication AS indicItem_gen4 ON indicItem_gen4.PatientID=patient.id
            INNER JOIN Medication AS indicMed_gen0 ON indicMed_gen0.ItemID=indicItem_gen4.id
            INNER JOIN Medication_DE AS indicDE_gen5 ON indicDE_gen5.id=indicMed_gen0.MedDictDE
            INNER JOIN NDCcodes AS indicCode_gen3 ON indicCode_gen3.NDC=indicDE_gen5.NDC AND indicCode_gen3.ingredient=6809
 LIMIT 30
