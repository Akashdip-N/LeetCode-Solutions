/*
    https://leetcode.com/problems/longest-palindromic-substring/
*/
/*
    Solution Approach:- Two pointers

    Time Complexity:- O(n^2)
    Space Complexity:- O(1)

    Explanation:-
        - There are two types of palindromes:
            a. odd-length (single center)
            b. even-length (two centers).
        - Odd length palindromes can be expanded from a single center,
            while even-length palindromes can be expanded from two centers.
        - For each character in the string,
            first we expand around it as a single center,
                then we expand around it and the next character as two centers.
        - We keep track and store the longest palindrome found during these expansions
        - Return the longest palindrome found.
*/

class Solution {
public:
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        string longest = "";

        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome (single center)
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > longest.size())
                longest = odd;

            // Even length palindrome (two centers)
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > longest.size())
                longest = even;
        }

        return longest;
    }
};
