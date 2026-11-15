/*
    https://leetcode.com/problems/decode-ways/
*/
/*
    Solution Approach:- Using Recursion & Memoization

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = Length of the input string (s)

    Problem Satement:-
        - Given a string containing only digits.
        - We need to decode the string into letters using the mapping:
            'A' -> 1
            'B' -> 2
            ...
            'Z' -> 26
        - We need to return the total number of ways to decode the string.
        - '06' is invalid because '0' cannot be mapped to any letter.

    Intuition:-
        - Using Recursion & memoization technique to solve this problem.
        - If the ith position character is 1, we can decode the substring in one way
            and if the ith position character is 2 and the next character is between 0 and 6,
                we can decode the substring in one way.
        - And in each recursive call, we will check if the result is already computed and
            stored in the memoization array.

    Explanation:-
        * Helper function `dfs()`:-
            - Takes the following as parameters:-
                i. i: The current index in the string.
                ii. s: The input string containing only digits.
                iii. memo: The memoization array to store the results of subproblems.
            - Base Case:-  If the current index is equal to the length of the string,
                            we have reached the end of the string, so we return 1
                                as there is one way to decode the string.
            - Condition 1:- If the result for the current index is already computed and stored in the
                                memoization array, we return that result.
            - Condition 2:- If the character at the current index is '0', we cannot decode it, so
                                we return 0.
            - We make a recursive call to decode the substring starting from the next index
                (i.e. i + 1) and store the result in a variable.
            - If the current position + 1 is less than the length of the string,
                that means we can check the next character as well.
            - If the current character is either '1' or '2' and the next character
                is between '0' and '6', that means all the valid combinations
                    of two digits characters can be created,
                so make a recursive call with the index incremented by 2 (i.e. i + 2)
                    and add the result to the previous result.
            - Finally, we store the result in the memoization array and return the result.

        * Main function `numDecodings()`:-
            - Takes the input string containing only digits as a parameter.
            - Initializes a memoization array of size equal to the length of the string
                and fills it with -1 to indicate that no results have been computed yet.
            - Calls the helper function `dfs()` with the initial index 0, the input string
                and the memoization array.
            - Returns the result of the helper function which is the total number of ways
                to decode the input string.
*/
class Solution {
    private:
        int dfs(int i, const string& s, vector<int>& memo) {
            if (i == s.size()) return 1;

            if (memo[i] != -1) return memo[i];

            if (s[i] == '0') return 0;

            int res = dfs(i + 1, s, memo);

            if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')))
                res += dfs(i + 2, s, memo);

            return memo[i] = res;
        }

    public:
        int numDecodings(string s) {
            vector<int> memo(s.size(), -1);
            return dfs(0, s, memo);
        }
};
