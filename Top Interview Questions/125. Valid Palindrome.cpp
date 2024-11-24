/*
    https://leetcode.com/problems/valid-palindrome/
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        int size = s.size();
        for (int i = 0; i < size; i++)
            if ((s[i] >= 'A' && s[i] <= 'Z'))
                a += tolower(s[i]);
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                a += s[i];

        int l = 0, r = (a.size() - 1);
        while (l < r){
            if(a[l] != a[r])
                return false;

            l++;
            r--;
        }
        return true;
    }
};