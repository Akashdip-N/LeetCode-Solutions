/*
    https://leetcode.com/problems/license-key-formatting/?source=submission-noac
*/
/*
    Solution Approach:- String Traversal From Back to Front

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = length of string s

    Explanation:-
        * We have to make sure that other than the first group, all other groups should have k characters.
        Ex:-
            s = "2-4A0r7-4k", k = 4
            Output: "24A0-R74K"
            Not: "2-4A0R-74K" (Because the last group does not have k characters)

        * So we will traverse the string from back to front and keep adding characters to the result string.
        * We will also keep track of the number of characters added to the result string.
        * If the number of characters added is equal to k, we will add a '-' to
            the result string and reset the character count to 0.
        * Finally, we will reverse the result string and return it.
*/
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ret = "";
        int charCount = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-')
                continue;

            if (charCount > 0 && charCount % k == 0) {
                ret += '-';
                charCount = 0;
            }

            ret += toupper(s[i]);
            charCount++;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
