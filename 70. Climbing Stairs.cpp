/*
    https://leetcode.com/problems/climbing-stairs/
*/
/*
    Solution Approach: Using Dynamic Programming (Memoization)

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of stairs

    Intuition:-
        - We have to find the best way we can reach the nth stair.
        - We can do this by taking either 1 or 2 steps at a time.
        - Using dynamic programming and memoization approach
            to store the previously calculated number of ways to reach the stairs.

    Explanation:
        * Using a helper function to compute the number of ways with which we can reach.
        * Inside the helper function we are performing the following operation:-
            i. Base case:-
                If n is 0 or 1 (that means we are in the first or second stair), return 1.
            ii. Checking if the number is already stored in the memo map,
                if yes then return the stored value.
            iii. Storing the number by calling the helper function recursively
                for n-1 and n-2 and adding the two values to
                    get the number of ways to reach the nth stair.
            iv. Finally returning the number of ways to reach the nth stair from the memo map.

        * In the main function we are calling the helper function
            using a hashmap to store the number of ways to reach the stairs.
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
    Solution Approach: Bottom up Dynamic Programming

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of stairs

    Intuition:-
        - The number of ways to reach the nth stair will always be 1
        - And the number of ways to reach the (n-1)th stair will always be 1
        - The number of ways to reach to the nth stair from the (n-1)th stair will be 1,
            because if we take 2 steps it would be out of bound.
        - So we would calculate from the end (n - 2) to the start (0) and
            find the number of ways to reach the nth stair.
        - This is similar to the Fibonacci sequence.

    Explanation:
        * Using 3 variables:-
            i. a = number of ways to reach the (n-1)th stair
            ii. b = number of ways to reach the (n-2)th stair
            iii. c = number of ways to reach the nth stair
        * Starting from the 2nd last stair and going to the 0th stair,
            we will calculate the number of ways to reach the nth stair.
        * At the end we will return the number of ways to reach the nth stair.
*/
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 1;

        for(int i = (n - 2); i >= 0; i--) {
            c = a;
            a += b;
            b = c;
        }

        return a;
    }
};
