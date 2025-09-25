/*
    https://leetcode.com/problems/department-highest-salary/
*/
/*
    Explanation:-
        Using the where clause to find the max salary,
            based on the departmentId of the outer query
                and that of the inner query
*/
select
    d.name as "Department",
    e.name as "Employee",
    e.salary as "Salary"
from Employee e
join Department d
on e.departmentId = d.id
where e.salary = (
    select MAX(salary)
    from Employee
    where departmentId = e.departmentId
);
