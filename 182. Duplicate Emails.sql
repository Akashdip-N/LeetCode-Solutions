/*
    https://leetcode.com/problems/duplicate-emails
*/
/*
    Explanation:-
        * Using group by to group the emails together.
        * Printing the emails whose count is more than one.
*/
SELECT email from Person
group by email
having count(email) > 1;
