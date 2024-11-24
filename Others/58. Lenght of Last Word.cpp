/*
    https://leetcode.com/problems/length-of-last-word/
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int size = s.size();
        while(size--){
            if(s[size] == ' ' && len !=0)
                return len;
            if(s[size] != ' ')
                len++;
        }
        return len;
    }
};