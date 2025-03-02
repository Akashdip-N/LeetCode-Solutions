/*
    https://leetcode.com/problems/climbing-stairs/
*/
/***************************** Memoization approach ******************************/
/*
    Solution:-
    * We are calling the function and storing the result in a map
        to avoid redundant calculations.
    * Then we are backtracking the function calls to get the final result.

    Ex:-
    n = 3

    First run:-
    memo[3] = countStairs(2, memo) + countStairs(1, memo);
    memo[2] = countStairs(1, memo) + countStairs(0, memo);
    memo[1] = countStairs(0, memo) + countStairs(-1, memo);

    Now we will backtrack the function calls to get the final result.

    memo[1] = 1
    memo[2] = memo[1] + 1 = 2
    memo[3] = memo[2] + memo[1] = 3

    So the final result is memo[3] = 3.
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

/****************** TOP DOWN APPROACH ***********************/
/*
    Solution:-

    Since the result will be sum of the previous two results.
    We can use dynamic programming to solve this problem.

    Ex:-
    n = 3,

    To go to the 3rd step, there are two ways:
    1. 1 + 1 + 1
    2. 1 + 2

    So, there are two methods to reach the 3rd step.


*/
class Solution {
public:
    int climbStairs(int n) {

        int a = 1, b = 1, c = 1;
        for(int i = 0; i < (n-1); i++){
            c = a;
            a += b;
            b = c;
        }

        return a;
    }
};
