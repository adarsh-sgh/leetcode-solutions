# Write your MySQL query statement below
SELECT name,bonus from Employee as e Left Join Bonus as b on e.empId = b.empId where ISNULL(b.bonus) OR b.bonus < 1000;