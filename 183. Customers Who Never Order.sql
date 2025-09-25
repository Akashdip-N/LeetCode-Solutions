/*
    https://leetcode.com/problems/customers-who-never-order
*/
/*
    Explanation:-
        * Printing the customer name from the Customer table
            such that the customer id is not present in the
                Order table.
*/
select name as Customers
from Customers
where id not in (
    select customerID
    from Orders
);
