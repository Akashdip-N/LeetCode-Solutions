/*
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
/*
    Solution Approach: Recursive backtracking approach.

    Explanation:-
    Ex:- 23
    Output:- ad ae af bd be bf cd ce cf

    * First we are creating a mapping of digits to their corresponding letters
    * Recursive function which takes input of digits, mapping, result, current string, and index.
    * Inside the function,
        * Base case: If the index is equal to the size of the digits string,
            (since the substring would of the same size of the input digits string)
                push the current string to the result vector and return.
        * Get the corresponding string from the mapping vector.
        * Iterating through each character of the corresponding string
            which is mapped to the current digit.
            * Push the current character to the current string.
            * Recursively call the function with the updated string and index.
            * Pop the last character from the current string,
                to get other combinations.
*/
class Solution {
public:
    void letterCombinationsUtil(
        string digits
        ,vector<string> mp
        , vector<string> &res // taking the location of the res vector
        , string s
        , int index
    ) {
        if(index == digits.size()) {
            res.push_back(s);
            return;
        }

        // We are subtracting the ASCII value of '0' from
        // the current digit to get the index in the mapping vector
        string str = mp[digits[index] - '0'];

        for(int i = 0; i < str.size(); i++) {
            s.push_back(str[i]);
            letterCombinationsUtil(digits, mp, res, s, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if(digits.size() == 0)
            return res;

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        //   0   1    2      3      4      5      6      7       8       9
        };

        string s = "";

        letterCombinationsUtil(digits, mp, res, s, 0);
        return res;
    }
};
