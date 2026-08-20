/*
    https://leetcode.com/problems/palindrome-number/
*/
/*
    Solution Approach:- Using math

    Time Complexity: O(logN)
    Space Complexity: O(1)
    N = number of digits in the number

    Intiuition:-
        - Given a number, we need to check if the number is a palindrome or not.
        - A number is a palindrome if it reads the same backward as forward.
        - First we would find the length of the number and
            the greatest power of 10 that is less than the number.
        - Then we would find the first and last digits of the number and
            check if they are equal.
        - If they are not equal, we would return false.
        - If they are equal, we would remove the first and last digits of the number
            and repeat the process until the number becomes 0 or 1 digit.

    Explanation:-
        * Base case:- If the number is a -ve number,
                    then we return false, since it's not a palindrome.

        * First finding the greatest power of 10 that is less than the number,
            because we need to find the first digit of the number.

            Ex:-
                Num = 12321
                The first digit would be:- 12321 / 10000 = 1
                The last digit would be:- 12321 % 10 = 1
        * Then we run a while loop until the number is not 0,
            and perform the following steps:-
                - Compare the first and the last digits of the number.
                - If they are not equal, we return false.
                - If they are equal, we remove the first and last digits of the number.
                - Update the divisor by dividing it by 100.

            Ex:-
                Iteration 1:-
                    Num = 12321
                    div = 10000,
                    First digit = num / div = 12321 / 10000 = 1,
                    Last digit = num % 10 = 12321 % 10 = 1,

                    Num = (num % div) / 10 = (12321 % 10000) / 10 = 232
                    Div = div / 100 = 10000 / 100 = 100

                Iteration 2:-
                    Num = 232
                    div = 100,
                    First digit = num / div = 232 / 100 = 2,
                    Last digit = num % 10 = 232 % 10 = 2,

                    Num = (num % div) / 10 = (232 % 100) / 10 = 3
                    Div = div / 100 = 100 / 100 = 1

        * Then we exit out of the loop that means the number is a palindrome and
            we return true.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long div = 1;
        while(x >= (div*10))
            div *= 10;

        while(x > 0){
            if ((x / div) != (x % 10))
                return false;

            x = (x % div) / 10;
            div /= 100;
        }

        return true;
    }
};

/**********************************************************************************************/
/*
    Solution Approach:- Using math

    Time Complexity: O(logN)
    Space Complexity: O(1)
    N = number of digits in the number

    Intuition:-
        - Storing the reverse of the number and comparing it with the original number.
        - If they are equal, then the number is a palindrome, then we return true.
        - Else we return false.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        long num = x;
        long newNum = 0;

        while(num > 0){
            int ele = num%10;
            newNum *= 10;
            newNum += ele;
            num /= 10;
        }

        return x == newNum;
    }
};

/**********************************************************************************************/
/*
    Solution Approach:- Using deque

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of digits in the number

    Intuition:-
        - Storing the reverse of the number and comparing it with the original number.
        - If they are equal, then the number is a palindrome, then we return true.
        - Else we return false.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        deque<int> dq;
        while (x > 0) {
            dq.push_back(x % 10);
            x /= 10;
        }

        while (dq.size() > 1) {
            if (dq.front() != dq.back())
                return false;

            dq.pop_front();
            dq.pop_back();
        }

        return true;
    }
};
