# Write your MySQL query statement below
SELECT name FROM
(SELECT a.name,count(*) AS CNT from Employee a Join Employee b on a.id = b.managerId GROUP BY a.id) AS A
WHERE CNT >= 5
;