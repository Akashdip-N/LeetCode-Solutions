/*
    https://leetcode.com/problems/excel-sheet-column-number/
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