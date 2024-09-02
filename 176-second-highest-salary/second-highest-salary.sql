# Write your MySQL query statement below
-- select distinct salary as SecondHighestSalary from Employee order by salary desc limit 1 offset 1;
select MAX(salary) as SecondHighestSalary from Employee where salary not in (select MAX(salary) from Employee);