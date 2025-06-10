/*
    https://leetcode.com/problems/powx-n
*/
/*
    Solution Approach: Using Recursion & Divide and Conquer

    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack

    Explanation:
        i. Base Cases:
            - If x is 0, return 0.
            - If n is 0, return 1 (since any number raised to the power of 0 is 1).
        ii. Recursive Case:
            - Store the result of the recursive call with n halved.
            - Square the result to account for the halved exponent.
            - If n is odd, multiply the result by x to account for the odd exponent.
                else return the squared result.
        iii. In the main function, handle negative powers
            by returning the reciprocal of the result.
*/
class Solution {
public:
    double fun(double x, long int n){
        if(x == 0) return 0;
        if(n == 0) return 1;

        double res = fun(x, n/2);
        res *= res;

        return n % 2 == 0 ? res : res * x;
    }

    double myPow(double x, long int n) {
        double res = fun(x, abs(n));
        return n < 0 ? 1 / res : res;
    }
};
