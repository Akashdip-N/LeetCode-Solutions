/*
    https://leetcode.com/problems/word-pattern
*/
/*
    Solution Approach:- Using Hash Map

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of string s

    Explanation:
        * Splitting the string s into words and storing them in a vector.
        * Check if the size of the pattern and words vector are equal.
            If not, that means the pattern does not match the string.
                return false.
        * Using two hash maps to store the mapping of characters in pattern to words in s and
            words in s to characters in pattern.
        * Using a loop to iterate through the pattern and words vector.
            * For each character in pattern and corresponding word in words vector,
                check if the mapping already exists in both hash maps.
                    If it exists, check if the mapping is consistent.
                        If not, return false.
            * If the mapping does not exist, create a new mapping in both hash maps.
        * If the loop completes without returning false, return true.
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int n = s.size();
        int j = 0;

        // checking the main string
        for (int i = 0; i <= n; ++i) {
            if (i == n || s[i] == ' ') {
                if (i > j)
                    words.push_back(s.substr(j, i - j));

                j = i + 1;
            }
        }

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Checking if the mapping already exists and the words/characters match
            if (m1.count(c) && m1[c] != w)
                return false;

            // Checking the reverse mapping
            if (m2.count(w) && m2[w] != c)
                return false;

            m1[c] = w;
            m2[w] = c;
        }

        return true;
    }
};
