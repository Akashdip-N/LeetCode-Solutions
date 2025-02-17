/*
    https://leetcode.com/problems/longest-palindromic-substring/
*/

/*                    LITTLE DIFFICULT PROBLEM!!!!!               */
/*
    Ex:- Input = "babad"
    Output = "bab" or "aba"


    Solution Approach:-

    1. We will use a sliding window approach.
    2. At first we are going to check for the odd length palindrome,
        i.e., we will take a character as the center and expand the window
                to the left and right side
    3. Then we will check for the even length palindrome,
        i.e., we will take two characters as the center and expand the window
                to the left and right side
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();

        if(size == 0)
            return "";

        string ret = "";
        int length = 0;

        for(int i = 0; i < size; i++){
            int l = i, r = i;
            // Odd length palindrome
            while(l >= 0 && r < size && s[l] == s[r]){
                if(r - l + 1 > length){
                    length = r - l + 1;
                    ret = s.substr(l, length);
                }
                l--;
                r++;
            }

            // Checking if the adjacent characters are same
            l = i, r = i + 1;
            while(l >= 0 && r < size && s[l] == s[r]){
                if(r - l + 1 > length){
                    length = r - l + 1;
                    ret = s.substr(l, length);
                }
                l--;
                r++;
            }
        }

        return ret;
    }
};
