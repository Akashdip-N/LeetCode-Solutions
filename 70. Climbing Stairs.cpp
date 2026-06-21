/*
    https://leetcode.com/problems/climbing-stairs/
*/
/*
    Solution Approach: Top Down Approach with Memoization

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of stairs

    Explanation:
        i. Start from the nth stair and recursively calculate the number of ways to
            reach the top by taking either 1 or 2 steps.
        ii. Using the base cases where if n is 0 or 1, there is only one way to reach the top.
        iii. Use a map to store the results of previously calculated stairs
            to avoid redundant calculations.
        iv. Finally, return the number of ways to reach the nth stair.
*/

class Solution {
public:
    int countStairs(int n, map<int, int>& memo) {
        if(n == 0 || n == 1)
            return 1;

        if(memo.find(n) != memo.end())
            return memo[n];

        memo[n] = countStairs(n - 1, memo) + countStairs(n - 2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        map<int, int> memo;
        return countStairs(n, memo);
    }
};

/**********************************************************************************************/
/*
    Solution Approach: Bottom Up Approach with Tabulation

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of stairs

    Explanation:
        i. Using three variables to store the number of ways to reach the current stair,
           the previous stair, and the stair before the previous stair.
        ii. Initialize all three variables to 1.
        iii. Iterate from 0 to n-1, updating the variables accordingly.
        iv. Finally, return the variable that stores the number of ways to reach the nth stair.
*/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 1;

        for(int i = 0; i < (n-1); i++) {
            c = a;
            a += b;
            b = c;
        }

        return a;
    }
};
