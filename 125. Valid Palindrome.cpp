/*
    https://leetcode.com/problems/valid-palindrome/
*/
/*
    Solution Approach:-

    * This is a two pointer problem.
    * Taking two pointers i and j, pointing to the start and end of the string.
    * Running the loop till (i < j)
    * checking if either left or the right side of the character are alphanumeric,
        then either incrementing or decrementing the counter

    * If the characters are not equal, then return false.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        bool ret = true;
        int i = 0, j = s.size() - 1;

        while(i < j){
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
        return ret;
    }
};
