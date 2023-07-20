# Write your MySQL query statement below
Select unique_id,name from Employees LEFT JOIN employeeUNI on Employees.id=employeeUNI.id;