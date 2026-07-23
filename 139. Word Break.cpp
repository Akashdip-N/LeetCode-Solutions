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

    Intuition:-
        * The idea is to reach the end of the string by checking the words from the wordDict.
        * Using array to store the whether it's possible to reach to that specific index or not.
        * At the end, we will return the value of the last index of the array,
            that will tell whether it's possible to reach the end of the string or not.

    Explanation:
        * Creating an array of string length + 1 and initializing it with false.
        * Base case where we have an empty string, and setting the first index to true.
        * Iterating through each index of the string and
            checking if any of the words in the wordDict can be used to reach that index.
        * If we can reach a index,
            where the size of the word is less than or equal to the current window.
        * Then we will check if whether it's possible to reach the index,
            (i - length of the word) and
                the substring in this window is equal to the word in the wordDict.
        * If both conditions are true, then we can reach the current index and we will set
            the value of that index to true and break the loop.

        Ex:-
            s = "applepenapple",
            wordDict = ["apple","pen"]

            dp = [true, false, false, false, false, false, false, false, false, false, false, false, false, false]

            i.
                i = 0,
                current window size = a
                No word in the wordDict can be used to reach this index.

            .... goint to index i = 5

            ii.
                i = 5
                current window size = apple
                wordsize = 5
                dp[5 - 5] = dp[0] = true
                substring = s.substr(5 - 5, 5) = apple
                word = apple

                Both conditions are true, so we can reach this index
                    and we will set dp[5] = true
                        and break the loop.

                dp = [true, false, false, false, false, true, false, false, false, false, false, false, false, false]

            ... going to index i = 8

            iii.
                i = 8
                current window size = applepen
                wordsize = 3
                dp[8 - 3] = dp[5] = true
                substring = s.substr(8 - 3, 3) = pen
                word = pen

                Both conditions are true, so we can reach this index
                    and we will set dp[8] = true
                        and break the loop.

                dp = [true, false, false, false, false, true, false, false, true, false, false, false, false, false]

            ... going to index i = 13

            iv.
                i = 13
                current window size = applepenapple
                wordsize = 5
                dp[13 - 5] = dp[8] = true
                substring = s.substr(13 - 5, 5) = apple
                word = apple

                Both conditions are true, so we can reach this index
                    and we will set dp[13] = true
                        and break the loop.

                dp = [true, false, false, false, false, true, false, false, true, false, false, false, false, true]

            v. Returning dp[13] = true, which means we can reach the end of the string.
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
