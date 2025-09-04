/*
    https://leetcode.com/problems/climbing-stairs/
*/
/*
    Solution Approach: Top Down Approach with Memoization

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of stairs

    Explanation:
        i. Using a helper function to count the number of ways to reach the nth stair.
        ii. Base case: if n is 0 or 1, return 1.
        iii. If the result is already in the memo map, return it.
        iv. Otherwise, calculate the result by calling the helper function for n-1 and n-2.
        v. Store the result in the memo map and return it.
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

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = number of stairs

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
