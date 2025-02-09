/*
    https://leetcode.com/problems/excel-sheet-column-number/
*/
/*
    Time Complexity: O(n)
    Space Complexity: O(1)
        Where 'n' is the length of the string columnTitle.

    Solution Approach:
    * For each string we have to calculate the number it represents.
    * We are storing the number which it represents in sum.
    * int d = c - 'A' + 1;
        In this we are subtracting the ASCII value of 'A' from the
            ASCII value of the character and adding 1 to it.
*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for(char c : columnTitle){
            int d = c - 'A' + 1;
            sum = (sum*26) + d;
        }

        return sum;
    }
};
