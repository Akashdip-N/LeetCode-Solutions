/*
    https://leetcode.com/problems/palindrome-number/
*/
class Solution {
public:
    bool isPalindrome(int x) {
        bool ch = true;
        if(x < 0)
            ch = false;
        else{
            long long int num = 0, temp = x, d = 0;
            while (temp > 0)
            {
                d = temp % 10;
                temp /= 10;
                num = ((num * 10) + d);
            }
            if (num == x)
                ch = true;
            else
                ch = false;
        }
        return ch;
    }
};
