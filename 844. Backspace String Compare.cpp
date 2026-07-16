/*
    https://leetcode.com/problems/backspace-string-compare/
*/
/*
    Solution Approach:- Using in-place string modification

    Time Complexity: O(N + M)
    Space Complexity: O(1)
    N = length of string s
    M = length of string t

    Explanation:-
        * We can use two pointers to iterate through the strings.
        * If we encounter a '#' character, we remove the previous character from the string.
        * If we encounter a normal character, we move the pointer to the next character.
        * Finally, we compare the two strings to see if they are equal.
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (i == 0) {
                    s.erase(i, 1);
                    i--;
                } else {
                    s.erase(i - 1, 2);
                    i -= 2;
                }

                if (i < -1)
                    i = -1;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (i == 0) {
                    t.erase(i, 1);
                    i--;
                } else {
                    t.erase(i - 1, 2);
                    i -= 2;
                }
                if (i < -1) i = -1;
            }
        }

        return s == t;
    }
};

/*************************************************************************************************/
/*
    Solution Approach:- Using Stack

    Time Complexity: O(N + M)
    Space Complexity: O(N + M)
    N = length of string s
    M = length of string t

    Explanation:-
        * We can use a stack to store the characters of the string.
        * If we encounter a '#' character, we pop the top character from the stack.
        * If we encounter a normal character, we push it onto the stack.
        * Finally, we compare the two stacks to see if they are equal.
*/
class Solution {
    private:
        stack<char> getChar(const string& s) {
            stack<char> s1;

            for (char c : s) {
                if (c == '#') {
                    if (!s1.empty())
                        s1.pop();
                }
                else
                    s1.push(c);
            }

            return s1;
        }

    public:
        bool backspaceCompare(string s, string t) {
            return getChar(s) == getChar(t);
        }
};

/*************************************************************************************************/
/*
    Solution Approach:- Similar to using Stack but using String instead of Stack
*/
class Solution {
    private:
        string processString(string str) {
            string result = "";
            for (char c : str) {
                if (c != '#') {
                    result.push_back(c);
                } else if (!result.empty()) {
                    result.pop_back();
                }
            }
            return result;
        }

    public:
        bool backspaceCompare(string s, string t) {
            return processString(s) == processString(t);
        }
};
