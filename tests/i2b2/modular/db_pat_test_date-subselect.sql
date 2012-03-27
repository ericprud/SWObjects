SELECT opt1.pat AS pat, opt1.typ AS typ, opt1.encDate AS encDate
       FROM (
SELECT _all_0_entry.patient_num AS pat, _all_0_entry.start_date AS encDate, CONCAT('http://informatics.kumc.edu/404/i2b2demo/testtype#T', _all_0_concept.concept_cd) AS typ, _all_0_concept.concept_cd AS _all_0_concept_cd
       FROM concept_dimension AS _all_0_concept
            INNER JOIN observation_fact AS _all_0_entry
 WHERE (_all_0_entry.concept_cd=_all_0_concept.concept_cd AND _all_0_entry.encounter_num='123')
             ) AS opt1
 LIMIT 10