# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary FROM EMPLOYEE WHERE salary < (SELECT MAX(SALARY) FROM EMPLOYEE);