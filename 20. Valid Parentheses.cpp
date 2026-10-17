/*
    https://leetcode.com/problems/valid-parentheses/
*/
/*
    Solution Approach: Using Stack

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the string

    Intuition:-
        - Given us a string containing the brackets '(', ')', '{', '}', '[' and ']'.
        - We have to check the order of the brackets,
            and return true if the order is valid, otherwise return false.

        - Using a stack to keep track of the brackets.
        - If the stack is empty, means we have all the brackets in the correct order,
            hence we return true, otherwise false.

    Explanation:-
        * Iterating from the starting index till the end of the string.
        * Performing the following operations in each step:-
            i. If we encounter an opening bracket, we push it onto the stack.
            ii. If we encounter a closing bracket, then we check the following conditions:-
                - If it's the first character, or
                - If the stack is empty, or
                - If the top of the stack is not the corresponding opening bracket,
                then we return false.
            iii. If the above conditions are not met, we pop the top of the stack.
        * At the end, we return true if the stack is empty, otherwise false.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                t.push(s[i]);
            else if(s[i] == ')') {
                if(i == 0 ||  t.empty() || t.top() != '(')
                    return false;
                t.pop();
            } else if(s[i] == ']') {
                if(i == 0 || t.empty() || t.top() != '[')
                    return false;
                t.pop();
            } else if(s[i] == '}') {
                if(i == 0 || t.empty() || t.top() != '{')
                    return false;
                t.pop();
            }
        }

        return t.empty();
    }
};
