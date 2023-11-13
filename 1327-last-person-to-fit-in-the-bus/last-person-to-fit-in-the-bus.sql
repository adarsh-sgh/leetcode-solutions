-- Write your PostgreSQL query statement below
SELECT person_name from
(SELECT person_name, (select sum(weight) from Queue as q2 where q2.turn <= q1.turn ) as csum from Queue as q1 ORDER BY csum DESC ) as t2 where csum <= 1000 LIMIT 1;