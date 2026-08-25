/*
    https://leetcode.com/problems/roman-to-integer/
*/
/*
    Solution Approach:- Using HashMap

    Time Complexity;- O(N)
    Space Complexity: O(1) (Fixed HashMap size)
    N = Length of the string

    Intuition:-
        - We have to find the integer value of the given roman numeral string.
        - Roman numerals rule are as follows:-
            i. If a smaller numeral appears before a larger numeral,
                it is subtracted from the larger numeral.
            ii. If a smaller numeral appears after a larger numeral,
                it is added to the larger numeral.
        - Using HashMap to fetch and store the integer value of each roman numeral character.
        - Iterating over the string and at the end returing the final value.

    Explanation:-
        * Creating a hashmap and storing the integer value of each roman numeral character.
        * Iterating over the string and checking the following conditions:-
            i. If the current character is smaller than the next character,
                then we subtract the current character's value from the final value.
            ii. If the current character is greater than or equal to the next character,
                then we add the current character's value to the final value.
        * At the end of the iteration, we return the final value.
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I']= 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int num = 0;

        for(int i = 0; i < s.size(); i++) {
            if ((i+1) < s.size() && (m[s[i]] < m[s[i+1]]))
                num -= m[s[i]];
            else
                num += m[s[i]];
        }

        return num;
    }
};
