SELECT opt1.pat AS pat, opt1.test AS test, opt1.encDate AS encDate
       FROM (
SELECT _all_0_entry.patient_num AS pat, _all_0_entry.start_date AS encDate, CONCAT("http://informatics.kumc.edu/testtype/", _all_0_concept.concept_cd) AS test, _all_0_concept.concept_cd AS _all_0_concept_cd
       FROM concept_dimension AS _all_0_concept
            INNER JOIN observation_fact AS _all_0_entry
 WHERE (_all_0_entry.concept_cd=_all_0_concept.concept_cd OR _all_0_entry.encounter_num="123")
             ) AS opt1
 LIMIT 10