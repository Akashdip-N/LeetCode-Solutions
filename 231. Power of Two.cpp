/*
    https://leetcode.com/problems/power-of-two
*/
/*
    Solution Approach: Using Recursion

    Time Complexity: O(log n),
        because the number is halved in each recursive call,
            same as binary search.

    Explanation:
        * We have 3 base cases:
            1. If n is less than or equal to 0, return false.
            2. If n is equal to 1, return true.
            3. If n is odd (n % 2 != 0), return false.

        * If none of these cases matches,
            we recursively call the function with n divided by 2.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        if (n == 1)
            return true;

        if (n % 2 != 0)
            return false;

        return isPowerOfTwo(n / 2);
    }
};

/************************************************************************/
/*
    Solution Approach: Using Bit Manipulation
    Time Complexity: O(1)

    Example:
        n = 16, binary representation is 10000
        n - 1 = 15, binary representation is 01111
        n & (n - 1) = 10000 & 01111 = 00000 (which is 0), that means n is a power of two.

    Explanation:
        * A number is a power of two if it has exactly one bit set in its binary representation.
        * The expression (n & (n - 1)) checks if n has only one bit set.
        * If n is a power of two, this expression will be equal to 0.
        * We also check if n is greater than 0 to handle negative numbers and zero.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};
