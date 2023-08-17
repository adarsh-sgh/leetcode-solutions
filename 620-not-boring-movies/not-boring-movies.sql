# Write your MySQL query statement below
SELECT * from Cinema where description != 'boring' AND id % 2 = 1 ORDER BY rating desc;