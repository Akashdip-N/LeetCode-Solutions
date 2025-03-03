/*
    https://leetcode.com/problems/valid-palindrome/
*/
/**************************** TWO POINTER SOLUTION *************************/
/*
    Solution Approach:-
    * Checking characters from both ends of the string.
    * If they are not equal, return false.
    * If they are equal, move the pointers towards the center
        and return true.
*/
class Solution {
public:
    bool isPalindrome(string s) {
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

        return true;
    }
};
