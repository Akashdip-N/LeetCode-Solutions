/*
    https://leetcode.com/problems/excel-sheet-column-title/
*/
/*
    Solution Approach:- Using Math

    Time Complexity: O(log N)
    Space Complexity: O(1)
    N = columnNumber

    Intuition:-
        - Given us a colum number, and we have to return the equivalent
            column title as appear in an Excel sheet.
        - The column title are represented as
            A -> 1
            B -> 2
            C -> 3
            ...
            Z -> 26
            AA -> 27
            AB -> 28
            ...

        - So in each iteration we can have in total of 26 possible values (A to Z).
        - Hence, for each iteration we would try to find the character possible,
            for that specific column number.
        - At the end we would reverse the string since we added the characters in reverse order.
        Ex:-
            columnNumber = 701
            Iteration 1:
                columnNumber = 700,
                columnNumber % 26 = 24 => character = 'Y'
                column = 'Y'

            Iteration 2:
                columnNumber = 25
                columnNumber % 26 = 25 => character = 'Z'
                column = 'YZ'

            Result = 'ZY' (after reversing the string)

    Explanation:-
        * Using a string to store the result consisting of characters.
        * Iterating while the column number is greater than 0,
            and performing the following operations:-
            i. Decrement the column number by 1, since we are using 0 based indexing.
            ii. Find the character corresponding to the column number by taking the modulo of 26.
            iii. Append the character to the result string.
            iv. Divide the column number by 26 to move to the next character.
        * Finally, reverse the result string and return it.
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string column;

        while(columnNumber > 0){
            columnNumber--;
            column += ('A' + columnNumber%26);
            columnNumber /= 26;
        }

        reverse(column.begin(), column.end());
        return column;
    }
};
