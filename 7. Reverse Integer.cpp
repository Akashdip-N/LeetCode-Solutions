/*
    https://leetcode.com/problems/reverse-integer/
*/
/*
    Solution:-
    * Modulus division to get the last digit of the number.
    * If the result is greater than INT_MAX or less than INT_MIN, we return 0.
*/
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0){
            result = (result*10) + (x % 10);
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN)? 0 : result;
    }
};
