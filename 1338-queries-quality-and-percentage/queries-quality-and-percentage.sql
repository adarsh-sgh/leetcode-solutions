# Write your MySQL query statement below
SELECT query_name, ROUND(AVG(rating/position),2) as quality
,ROUND(100 * AVG(rating < 3),2) as poor_query_percentage from Queries GROUP BY query_name;