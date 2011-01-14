SELECT _all_0_entry.patient_num AS pat, _all_0_entry.start_date AS encDate, CONCAT("http://informatics.kumc.edu/404/i2b2demo/testtype#T", _all_0_concept.concept_cd) AS typ
       FROM concept_dimension AS _all_0_concept
            INNER JOIN observation_fact AS _all_0_entry
 WHERE (_all_0_entry.concept_cd=_all_0_concept.concept_cd OR _all_0_entry.encounter_num="123")
 LIMIT 10