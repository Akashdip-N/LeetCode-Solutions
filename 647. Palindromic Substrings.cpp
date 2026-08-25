/*
    https://leetcode.com/problems/palindromic-substrings/
*/
/*
    Solution Approach:- Using Two Pointer

    Time Complexity: O(N^2)
    Space Complexity: O(1)
    N = length of the string

    Intuition:-
        - We have to find the number of palindromic substrings in the given string.
        - We would iterate through the entire string from position 0
            till the end of the string.
        - For each position, we would check for odd length palindromes
            and even length palindromes.
            (
                Similar implementation as `5. Longest Palindromic Substring` problem
                https://leetcode.com/problems/longest-palindromic-substring/
            )
        - At the end, we would return the count of palindromic substrings.

    Explanation:-
        Helper function:-
            * Taking the following as input parameters:-
                - The string
                - The left pointer
                - The right pointer
                - The count variable
            * Expanding to both sides for that specific position
                and incrementing the count variable for each palindromic substring found.

        Main function:-
            * Creating a count variable to keep track of the number of palindromic substrings.
            * Iterating from position 0 to the end of the string.
            * Calling the helper function first for the odd length palindrome
                and then for the even length palindrome.
            * And finally returning the count of palindromic substrings.
*/
class Solution {
public:
    void palindromeLength(string& s, int left, int right, int& count){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
    }

    int countSubstrings(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            palindromeLength(s, i, i, count);
            palindromeLength(s, i, i + 1, count);
        }

        return count;
    }
};

/**********************************************************************************************/
/*
    Solution Approach:- Using Manacher's Algorithm

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the string

    Intuition:-
        - We have to find the number of different palindromic substrings in the given string.
        - Using Manacher's Algorithm,
            we can find the number of palindromic substrings in linear time.
        - We would transform the string by adding special characters,
            both at the start and the end of the string,
                as well in between each character of the string.
        Ex:-
            Input String:- "abba"
            Transformed String:- "@#a#b#b#a#$"
        - Using vector to store the half length of the longest palindromic
            substring centered at that specific position.
        - At the end, we would return the total number of palindromic substrings found.

    Explanation:-
        * Adding the special characters to and storing the transformed string in a new variable.
        * Creating a vector of length same as the tranformed string and initializing it with 0.
        * Creating two variables, center and right, to keep track of the center and right boundary
            of the current longest palindromic substring.
        * Using another variable (totalPalindrome) to keep track of the total number
            of palindromic substrings found.
        * Iterating through index 1 till the second last index of the transformed string.
            (
                Because the first and last characters are special characters,
                    we don't need to check for them.
            )
        * And performing the following operations:-
            - Finding the left mirror of the current index using the formula,
                mirror = 2 * center - left
                (
                    Explanation:-
                        center = (left + mirror) / 2
                        => 2 * center = left + mirror
                        => mirror = 2 * center - left
                )
            - If the right boundary is greater than the current index,
                we would update the half length of the longest palindromic substring
                    centered at the current index with the minimum of
                        the right boundary - current index and
                        the half length of the longest palindromic substring
                            centered at the left mirror of the current index.
            - Then we would expand to both sides of the current index
                and check if the characters are equal or not,
                    and increment the half length of the longest palindromic substring
                        centered at the current index for each palindromic substring found.
            - If the right boundary is less than the current index + half length of the
                longest palindromic substring centered at the current index,
                    we would update the center and right boundary with the current index and
                        the current index + half length of the longest palindromic substring
                            centered at the current index.
            - Finally, we would increment the total number of palindromic substrings
                found with the half length of the longest palindromic substring centered
                    at the current index + 1 divided by 2.
        * At the end, we would return the total number of palindromic substrings found.
*/
class Solution {
public:
    int countSubstrings(string s) {
        string newString = "@";
        for (char c : s) {
            newString += "#";
            newString += c;
        }
        newString += "#$";

        int size = newString.size();
        vector<int> loc(size, 0);
        int center = 0, right = 0;
        int totalPalindromes = 0;

        for (int left = 1; left < (size - 1); left++) {
            int left_mirror = 2 * center - left;

            if (right > left)
                loc[left] = min(right - left, loc[left_mirror]);

            while (newString[left + 1 + loc[left]] == newString[left - 1 - loc[left]])
                loc[left]++;

            if (left + loc[left] > right) {
                center = left;
                right = left + loc[left];
            }

            totalPalindromes += (loc[left] + 1) / 2;
        }

        return totalPalindromes;
    }
};
