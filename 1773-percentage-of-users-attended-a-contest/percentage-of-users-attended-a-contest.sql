# Write your MySQL query statement below
SELECT contest_id,ROUND(count(distinct(register.user_id))/count(distinct(users.user_id)) * 100,2) as percentage FROM Users, Register 
 GROUP BY contest_id
ORDER BY percentage desc, contest_id asc
 ;