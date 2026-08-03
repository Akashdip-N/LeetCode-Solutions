/*
    https://leetcode.com/problems/fibonacci-number/
*/
/*
    Solution Approach:- Iterative approach

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of elements in the Fibonacci sequence

    Intuition:-
        * Fibonacci sequence is all about finding the sum of the earlier two numbers
            for the current number.
        * Using the earlier two number and storing the sum of the current number in a variable.
            and updating the earlier numbers for the next iteration.

    Explanation:-
        * Initialize two variables a and b with 0 and 1 respectively.
        * Iterating from 2 to n, while do so performing the following steps:
            - Calculate the sum of a and b and store it in c.
            - Update a with the value of b.
            - Update b with the value of c.
        * At the end we check if n is 0 then we return a(0)
            otherwise we return b (the nth Fibonacci number).
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
    Solution Approach:- Using Dynamic Programming (Memoization)

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of elements in the Fibonacci sequence

    Intuition:
        - Since we are using recursive method to calculate the Fibonacci number.
        - Storing the previously computed Fibonacci numbers in a vector to avoid recomputation.
        - At the end returning the nth Fibonacci number from the memo vector.

    Explanation:
        * Using a helper function to compute the Fibonacci number recursively.
            - Inside the helper function we are checking the following:-
                i. Base case:- If n is less than or equal to 1, return n (i.e., 0 or 1).
                ii. Checking if the number is already stored in the memo vector,
                    if yes then return the stored value.
                iii. Storing the number by calling the helper function recursively
                    for n-1 and n-2 and returning the sum.
                iv. At the end returning the nth Fibonacci number from the memo vector.
        * In the main funciton
            - Initializing a vector of size (n + 1) with -1 to store the numbers
            - Calling the helper function with n and the memo vector.
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

    Time Complexity: O(N)
    Space Complexity: O(N) (due to recursion stack)
    N = number of elements in the Fibonacci sequence

    Intuition:
        - This solution is the combination between the iterative and recursive approach.
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

    Time Complexity: O(2^N)
    Space Complexity: O(N) (due to recursion stack)
    N = number of elements in the Fibonacci sequence

    Intuition:-
        - The problem requires the sum of the previous two numbers to find the current number.
        - We call the same function recursively for n-1 and n-2 until we reach the base case.
        - Then we return the sum of the two numbers to get the nth Fibonacci number.

    Explanation:-
        * Base case:-
            i. If n is 0, return 0
            ii. If n is 1 or 2, return 1.
        * Otherwise,
            return the sum of fib(n - 1) and fib(n - 2) to get the nth Fibonacci number.
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
