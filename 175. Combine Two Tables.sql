/*
    https://leetcode.com/problems/combine-two-tables
*/
/*
    Explanation-
        * Since we have to show 'NULL' values in the city and state column,
            in places where the personID is missing.
        * Using 'LEFT JOIN' to print 'NULL' in values where
            the values are missing from the second table.
*/
SELECT P.firstName, P.lastName, A.city, A.state
FROM Person P LEFT JOIN Address A
on P.personId = A.personId
