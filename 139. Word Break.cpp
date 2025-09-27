/*
    https://leetcode.com/problems/word-break/description/
*/
/*
    Solution Approach:- Using Dynamic Programming

    Time Complexity: O(N * M * K)
    Space Complexity: O(N)
    N = Length of the string s
    M = Number of words in the wordDict
    K = Average length of the words in the wordDict

    Explanation:
        * Using a vector of boolean values and inialize it to false.
        * The size of the vector is n + 1, where n is the length of the string s.
        * Iterate through the string and for each position, check all words in the
            dictionary to see if they can form a valid segment ending at that position.
        * If a valid segment is found, mark the position as true in the dp array.
        * Finally, return the value at dp[n], which indicates whether the entire
            string can be segmented.
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n + 1, false);

        // Base case: empty string can be segmented
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (const string& word : wordDict) {
                int len = word.size();

                if (i >= len && dp[i - len] && s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
