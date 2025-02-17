/*
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/
class Solution {
public:
    void letterCombinationsUtil(
        string digits, vector<string> mp, vector<string> &res, string s, int index
    ) {
        if(index == digits.size()) {
            res.push_back(s);
            return;
        }

        // Get the string for the current digit
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
