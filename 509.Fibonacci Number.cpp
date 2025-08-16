/*
    https://leetcode.com/problems/fibonacci-number/
*/
/*
    Solution Approach:- Iterative approach

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = number of elements in the Fibonacci sequence

    Explanation:
        - Use two variables to store the last two Fibonacci numbers.
        - Iterate from 2 to n, updating the variables to compute the next Fibonacci number.
        - Return the nth Fibonacci number.
*/
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c;

        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        return n == 0 ? a : b;
    }
};

/*****************************************************************************************/
/*
    Solution Approach:- Recursive approach with memoization

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of elements in the Fibonacci sequence

    Explanation:
        - Use a helper function to compute the Fibonacci number recursively.
        - Use a vector to store previously computed Fibonacci numbers (memoization).
        - If the Fibonacci number for n is already computed,
            return it from the memo vector.
        - Otherwise, compute it recursively and store the result in the memo vector.
        - Return the memoized nth value.
*/
class Solution {
public:
    int fibHelper(int n, vector<int>& memo) {
        if (n <= 1)
            return n;

        if (memo[n] != -1)
            return memo[n];

        memo[n] = fibHelper(n - 1, memo) + fibHelper(n - 2, memo);
        return memo[n];
    }

    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return fibHelper(n, memo);
    }
};

/*****************************************************************************************/
/*
    Solution Approach:- Tail recursive approach

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of elements in the Fibonacci sequence

    Explanation:
        - Use a helper function to compute the Fibonacci number using tail recursion.
        - The helper function takes two parameters (a and b) representing
            the last two Fibonacci numbers, a count of how many numbers have been computed,
            and the target n.
        - If the count equals n, return a (the nth Fibonacci number).
        - Otherwise, recursively call the helper function with updated values.
*/
class Solution {
public:
    int fibHelper(int a, int b, int count, int n) {
        if (count == n)
            return a;

        return fibHelper(b, a + b, count + 1, n);
    }

    int fib(int n) {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return fibHelper(1, 2, 2, n);
    }
};

/*****************************************************************************************/
/*
    Solution Approach:- Recursive approach without memoization

    Time Complexity: O(2^n)
    Space Complexity: O(n)
    n = number of elements in the Fibonacci sequence

    Explanation:
        - Use a recursive function to compute the Fibonacci number.
        - Base cases:
            - If n is 0, return 0.
            - If n is 1 or 2, return 1.
        - Recursively call the function for n-1 and n-2 and return their sum.
        - This approach has exponential time complexity due to repeated calculations.
*/
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;

        if (n == 1 || n == 2)
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};
