/*
    https://leetcode.com/problems/longest-palindromic-substring/
*/
/*
    Solution Approach:- Using Two pointers

    Time Complexity:- O(N^2)
    Space Complexity:- O(1)
    N = size of the input string

    Intuition:-
        - We have to find the longest size palindrome substring from the given string.
        - How would we do that we would take a index from the string,
            and would expand to both left and right sides
                and would check if the characters are equal or not.
        - There can be two possibilities for the palindrome substring:
            a. odd-length (single center)
                Example: "aba" (center is 'b')

            b. even-length (two centers).
                Example: "abba" (centers are 'b' and 'b')
        - We would check for both possibilities for each character in the string.
        - Store the string in each case and
            compare the length of the string with the longest palindrome found so far.
        - At the end we would return the longest palindrome string that we found.

    Explanation:-
        * Main function (longestPalindrome):-
            * Base case:- If the string is empty, return an empty string.

            * Iterating through each index of the string,
                and performing the following steps:
                i. To find if the string is a palindrome with odd length,
                    we pass the current index as both left and right pointers,
                        along with the string to the helper function.
                ii. Then based on the string which we have received,
                        we check if the length of the string that is returned
                            is greater than the length of the longest palindrome
                                string found so far.
                iii. To find if the string is a palindrome with even length,
                        we pass the current index as the left pointer and
                            the next index as the right pointer,
                                along with the string to the helper function.
                iv. Then we again check the lenght of the string that is returned with
                        the length of the longest palindrome string found so far.
            * Finally, we return the longest palindrome string that we found.

        * Helper function (expandAroundCenter):-
            - Take the current string, left and right pointers as input.
            - While the left pointer is greater than or equal to 0 and
                the right pointer is less than the size of the string and
                    the characters at the left and right pointers are equal,
                        we decrement the left pointer and increment the right pointer,
                            thus, expanding the window to both sides.
            - Finally, we return the substring from the
                left pointer + 1 to the right pointer - left pointer - 1,
                    which is the longest palindrome substring found for the current center.
                (
                    we are taking this substring because, when the while loop breaks,
                        both the left and right pointers are at the index
                            where the chacracters are not equal,
                    that's why we are adding 1 to the left pointer and
                        subtracting 1 from the right pointer to get the correct substring.
                )
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
