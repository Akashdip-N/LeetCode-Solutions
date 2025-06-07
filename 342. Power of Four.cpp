/*
https://leetcode.com/problems/power-of-four
*/
/*
    Solution Approach: Using Recursion

    Same as problem 231. Power of Two, but with a different base case.
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        if (n == 1)
            return true;

        if (n % 4 != 0)
            return false;

        return isPowerOfFour(n / 4);
    }
};

/************************************************************************/
/*
    Solution Approach: Using Bit Manipulation
    Time Complexity: O(1)

    Example:
        n = 16, binary representation is 10000
        n - 1 = 15, binary representation is 01111
        n & (n - 1) = 10000 & 01111 = 00000 (which is 0),
            that means n is a power of two.

    Explanation:
        * A number is a power of two if it has exactly one bit set
            in its binary representation.
        * The expression (n & (n - 1)) checks if n has only one bit set.
        * If n is a power of two, this expression will be equal to 0.
        * We also check if n is greater than 0 to handle negative
            numbers and zero.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};
