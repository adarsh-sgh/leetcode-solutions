# Write your MySQL query statement below
SELECT teacher_id, count(distinct subject_id) as cnt from Teacher GROUP By teacher_id;