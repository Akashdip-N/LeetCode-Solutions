/*
    https://leetcode.com/problems/rising-temperature/
*/
/*
    Explanation:-
        * Using DATEDIFF function to make sure that the difference in date is not more than 1
        * Using conditional operator to find the correct id
*/
select w1.id as Id
from Weather w1
join Weather w2
where
    DATEDIFF(
        w1.recordDate,
        w2.recordDate
    ) = 1
        AND
    w1.temperature > w2.temperature
;
