/*
    https://leetcode.com/problems/longest-palindrome
*/
/*
    Solution Approach: Using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input string

    Explanation:
        - First we count the number of occurrences of each character of the string.
        - For all the even counts, we can use all of them in the palindrome.
        - For the odd number of occurrences, we can use 1 less than the count
            (to make it even), we use boolean variable to check this.
        - If there is at least one character with an odd count,
            we add 1 to the length of the palindrome,
                since we can place one odd character in the middle.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;

        for(char c : s)
            charCount[c]++;

        int length = 0;
        bool hasOddCount = false;

        for(const auto& pair : charCount) {
            if(pair.second % 2 == 0)
                length += pair.second;
            else {
                length += pair.second - 1;
                hasOddCount = true;
            }
        }

        if(hasOddCount)
            length += 1;

        return length;
    }
};
