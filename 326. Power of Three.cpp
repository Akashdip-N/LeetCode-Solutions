/*
    https://leetcode.com/problems/power-of-three/
*/
/*
    Solution Approach:- Using Mathematical Approach

    Time Complexity:- O(1)
    Space Complexity:- 1
    N = input number

    Intuition:-
        - The maximum power of 3 that can fit in a 32-bit signed integer is 3^19 = 1162261467.
        - If n is a power of 3, then it must be a divisor of 1162261467.
        - So, we can check if 1162261467 is divisible by n or not.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

/***********************************************************************************/
/*
    Solution Approach:- Using Iterative Approach & Multiplication Method

    Time Complexity:- O(log3(N))
    Space Complexity:- 1
    N = input number

    Intuition:-
        - Finding if we can reach the number by multiplying 3 with itself.
        - We can keep multiplying 3 with itself until we reach the number or exceed it.
        - If we reach the number, then it is a power of 3, otherwise it is not.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        long i = 1;

        while(i <= n){
            if (i == n)
                return true;
            i *= 3;
        }

        return false;
    }
};

/***********************************************************************************/
/*
    Solution Approach:- Using Iterative Approach & Division Method

    Time Complexity:- O(log3(N))
    Space Complexity:- 1
    N = input number

    Intuition:-
        - Can we reach 1 or 0 by dividing the number by 3 repeatedly?
        - If we can reach 1, then it is a power of 3, otherwise it is not.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        while(n % 3 == 0)
            n /= 3;

        return n == 1;
    }
};


/***********************************************************************************/
/*
    Solution Approach:- Using Recursive Approach & Division Method

    Time Complexity:- O(log3(N))
    Space Complexity:- O(log3(N)) (due to recursive call stack)
    N = input number

    Intuition:-
        - Can we reach 1 or 0 by dividing the number by 3 repeatedly?
        - If we can reach 1, then it is a power of 3, otherwise it is not.
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;

        if(n == 1) return true;

        return (n % 3 == 0) && (isPowerOfThree(n/3));
    }
};
