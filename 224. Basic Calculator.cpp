/*
    https://leetcode.com/problems/basic-calculator/
*/
/*
    Solution Approach:- Using Stack

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = Length of the string

    Intuition:-
        - Given us a string which contains digits, '+', '-', '(', ')', and spaces.
        - We need to evaluate the expression and return the result.
        - We can't use any inbuilt string to integer conversion functions.

        - We would use stack to keep track of the result of the expression so far.
        - Using a sign variable to store either 1 or -1 to keep track of the sign
            of the current number.
        - When we encounter a number in the string, we would multiply the current number with 10,
            and then convert the character into a integer and add it to the current number.
        - THIS IS SPECICIALLY USEFUL WHEN WE HAVE MULTI-DIGIT NUMBERS IN THE STRING

    Explanation:-
        * Creating a stack with data type integer to store the result as
            well as the sign of the current number.
        * Creating a variable to store the result of the expression so far,
            and a variable to store the current number being processed.
        * Iterating from index 0 till the end of the string,
            and performing the following operations based on the current character encountered.
        * If the current character encountered is a digit, then multiplying current number with 10,
            then convert the current character into a integer and adding it to the current number.
            (
                Ex:-
                    s = "123 + 456"
                    currentNum = 0
                    i = 0, c = '1', currentNum = 0 * 10 + (1 - '0') = 1
                    i = 1, c = '2', currentNum = 1 * 10 + (2 - '0') = 12
                    i = 2, c = '3', currentNum = 12 * 10 + (3 - '0') = 123
            )
        * If the current character encountered is a '+', then we add whatever the current number is,
            after multiplying it with the sign, to the result.
                (
                    Ex:-
                        s = "123 + 456"
                        currentNum = 123
                        sign = 1
                        result = 0
                        i = 3, c = '+', result = 0 + (1 * 123) = 123
                )
            And setting the current number to 0, and the sign to 1.
        * If the current character encountered is a '-',
            performing the same operations as above, but setting the sign to -1.
        * If the current character encountered is a '(',
            then pushing the current result so far, and the current sign so far, to the stack.
            And setting the result to 0, and the sign to 1.
        * If the current character encountered is a ')',
            first we multiply the current number with the sign, and add it to the result.
            - Then we pop the sign from the stack, and multiply the result with it.
            - Then we pop the result from the stack, and add it to the current result.
        * Finally, we return the result after adding the current number multiplied with the sign.
            (
                Ex:-
                    s = "123 + 456"
                    currentNum = 456
                    sign = 1
                    result = 123
                    i = 7, c = '6', result = 123 + (1 * 456) = 579

                    The final result is 579
            )
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long currentNum = 0;
        long long result = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c))
                currentNum = currentNum * 10 + (c - '0');
            else if (c == '+') {
                result += sign * currentNum;
                currentNum = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * currentNum;
                currentNum = 0;
                sign = -1;
            }
            else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * currentNum;
                currentNum = 0;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }

        return result + (sign * currentNum);
    }
};
