/*
    https://leetcode.com/problems/valid-parentheses/

    Problem:- We have to check if the stack is empty at the end or not.

    Explantion:-
    * When we are encountering a opening bracket we are pushing it into the stack.
    * When we are encountering a closing bracket,
        we are checking if the stack is empty or not.
            If it is empty, which means that the order of brackets are wrong,
                then we are returning false
        Else,
            we are poping the bracket from the stack.
    * We are returing the whether the stack is empty or not.
        If it is empty, then the order of brackets are correct.
        Else, the order of brackets are wrong.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                t.push(s[i]);
            else
                if(s[i] == ')') {
                    if(i == 0 ||  t.empty() || t.top() != '(')
                        return false;
                t.pop();
            } else
                if(s[i] == ']') {
                    if(i == 0 || t.empty() || t.top() != '[')
                        return false;
                t.pop();
            } else
                if(s[i] == '}') {
                    if(i == 0 || t.empty() || t.top() != '{')
                        return false;
                t.pop();
            }
        }
        return t.empty();
    }
};
