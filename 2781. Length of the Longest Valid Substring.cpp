/*
    https://leetcode.com/problems/length-of-the-longest-valid-substring/
*/
/*
    Solution Apporach: Sliding Window Approach

    Time Complexity: O(n * m)
    Space Complexity: O(m)
    n = length of the word

    Explanation:
    - Using hashset to store forbidden substrings for O(1) lookup.
    - Storing the maximum length of the substring in maxLen variable.
    - Using two pointers (l and r) to maintain the current valid substring.
    - For each substring, checking if there is any forbidden character,
        with the help of the set.
    - If a forbidden substring is found, move the left pointer (l) to the right
        of the forbidden substring.
    - at the end of the loop, update the maxLen with the maximum length
        of the valid substring found so far.
    - Return the maxLen as the result.
*/
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();
        unordered_set<string> forbiddenSet(forbidden.begin(), forbidden.end());

        // Find max forbidden length
        int maxForbiddenLength = 0;
        for (const string& s : forbidden)
            maxForbiddenLength = max(maxForbiddenLength, (int)s.size());

        int maxLen = 0;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            // Check all suffixes ending at r
            for (int len = 1; (len <= maxForbiddenLength) && (len <= (r - l + 1)); ++len) {
                string suffix = word.substr(r - len + 1, len);
                if (forbiddenSet.count(suffix)) {
                    l = r - len + 2;
                    break;
                }
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
