/*
    https://leetcode.com/problems/basic-calculator-ii/
*/
/*
    Solution Approach:- Using Stack

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the input string

    Intuition:-
        - Given a string of expression consisting of number and operators,
            we have to evaluate the expression and return the result.
        - We would use stack to store the number either positive
            or negative value based on the operator.
        - If the operator is not '+' or '-',
            then we would pop the top element from the stack and perform the operation
                and push the result back to the stack.
        - At the end we would pop the elements from the stack and return the result.

    Explanation:
        * Using stack to store the numbers present in the expression.
        * Using a variable to store the current operator and initializing it to '+'.
        * Iterating from index (0) till the end of the string and performing the following steps:-
            i. Checking if the current character is a digit or not,
                if it is then converting the character into integer
                    using the formula (currentNum = currentNum * 10 + (c - '0'))
                        and storing it in the currentNum variable.
                (
                    Ex:- chararacter = '3' => currentNum = 0 * 10 + (3 - '0') = 3
                    Ex:- chararacter = '4' => currentNum = 3 * 10 + (4 - '0') = 34
                )
            ii. If the current character is not a digit and is not a space
                    or if we have reached the end of the string,
                then we would check the current operator and perform the following steps:-
                    - If the operator is '+',
                        then we would push the currentNum to the stack.
                    - If the operator is '-',
                        then we would push the negative of currentNum to the stack
                    - If the operator is '*',
                        then we would pop the top element from the stack,
                            multiply it with the currentNum and
                                push the result back to the stack.
                    - If the operator is '/',
                        then we would pop the top element from the stack,
                            divide it with the currentNum and
                                push the result back to the stack.
            iii. After that we would update the current operator with the current character
                and reset the currentNum to 0.
        * After the iteration is complete, we would pop the elements from the stack and
            return the sum of all the elements present in the stack
                as the result of the expression.
*/
class Solution {
public:
    int calculate(string s) {
        int size = s.size();
        stack<int> st;
        long currentNum = 0;
        char op = '+';

        for (int i = 0; i < size; i++) {
            char c = s[i];

            if (isdigit(c))
                currentNum = currentNum * 10 + (c - '0');

            if ((!isdigit(c) && !isspace(c)) || i == size - 1) {
                if (op == '+')
                    st.push(currentNum);
                else if (op == '-')
                    st.push(-currentNum);
                else if (op == '*') {
                    int prev = st.top();
                    st.pop();
                    st.push(prev * currentNum);
                } else if (op == '/') {
                    int prev = st.top();
                    st.pop();
                    st.push(prev / currentNum);
                }

                op = c;
                currentNum = 0;
            }
        }

        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};
