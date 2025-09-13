/*
    https://leetcode.com/problems/valid-parentheses/
*/
/*
    Solution Approach: Using Stack

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = length of the string

    Explanation:-
        * Stack to keep track of opening brackets.
        * Iterate through each character in the string.
        * If it's an opening bracket, push it onto the stack.
        * If it's a closing bracket,
            check if it is the first character or the stack is empty
                or it is not matching with the top of the stack.
                    then return false
        * Else continue popping the top of the stack.
        * Finally, if the stack is empty, return true, else false.
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
