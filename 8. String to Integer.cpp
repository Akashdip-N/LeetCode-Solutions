/*
    https://leetcode.com/problems/string-to-integer-atoi/
*/
/*
    Solution Approach:- Using String Manipulation

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = number of characters in the input string

    Intuition:-
        - We have to return the number that is represented by the string.
        - We have also consider the following cases,
            i. If the string is empty, return 0.
            ii. If the string has leading spaces, ignore them.
            iii. If the string has a sign (+ or -), consider it.
            iv. If the string has non-digit characters, ignore them.
            v. If the number is out of range, return INT_MAX or INT_MIN.

    Explanation:-
        * Iterating over the string and ignoring the leading spaces.
        * Checking if the next character is a sign (+ or -),
            if it is, we would consider it and move to the next character.
        * Then we would iterate over the string and check if the character is a digit,
            if it is, we would convert it to an integer and add it to the number.
        * If the number is out of range, we would return INT_MAX or INT_MIN.
        * Finally, we would return the number with the sign.
*/
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int i = 0;

        while(i < size && s[i] == ' ' )
            i++;

        int sign = 1;
        if(i < size && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-')
                sign = -1;
            i++;
        }

        long long int num = 0;
        while(i < size && isdigit(s[i])){
            int digit = s[i] - '0';
            num = num * 10 + digit;

            if(sign * num >= INT_MAX) return INT_MAX;
            if(sign * num <= INT_MIN) return INT_MIN;

            i++;
        }

        return (sign * num);
    }
};
