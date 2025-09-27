/*
    https://leetcode.com/problems/valid-palindrome/
*/
/*
    Solution Approach: Using Two Pointers

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the string

    Explanation:
        * Using two pointers,
            one from the start of the string i.e. i = 0,
                and the other from the end of the string i.e. j = s.size() - 1
        * Move the pointers towards each other until they meet in the middle.
        * If the characters at both pointers are not alphanumeric,
            move the respective pointer.
        * Checking if the characters are not equal,
            then return false.
        * If the characters are equal,
            move both pointers towards each other.
        * At the end, if all characters are equal,
            return true.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {
            if(!isalnum(s[i])){
                i++;
                continue;
            }

            if(!isalnum(s[j])){
                j--;
                continue;
            }

            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }

        return true;
    }
};
