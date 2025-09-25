/*
    https://leetcode.com/problems/employees-earning-more-than-their-managers
*/
/*
    Explanation:-
        * Joining the same table,
            with the condition that Employee ID = Manager ID
        * Putting condition that is
            Employee salary > manager salary
*/
select e.name as Employee
from Employee e
join Employee b
where e.managerId = b.id
and e.salary > b.salary;
