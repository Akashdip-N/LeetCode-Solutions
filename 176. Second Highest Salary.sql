/*
    https://leetcode.com/problems/second-highest-salary
*/
/*
    Explanation:-
        * Executing second query inside a query,
            such that we can get the 2nd highest salary in the table.
        * Using limit query to fetch single value from the query.
        * Using offset keyword to remove the desired number of
            values from the query results.
*/

select (
    select distinct Salary
    from Employee order by salary desc
    limit 1
    offset 1
)
as SecondHighestSalary;
