/*
    https://leetcode.com/problems/generate-parentheses
*/
/*
    Intuition:-
        We will add '(' and ')' to the current string until we reach the desired length.

    Solution Approach:-
        Using recursion and backtracking

    Code:-
        * We have a base case where if the number of "(" brackets is equal
            to the number of ")" brackets, we have a valid combination,
                and we can add the current string to the result.
        * If the number of "(" brackets is more than 0,
            then we will add "(" to the current string,
                and will call the function again.
        * If the number of ")" brackets is less than the number of "(" brackets,
            then we will add ")" to the current string,
                and will call the function again.
        * For the if statements will be backtrack it
            by popping the last character from the current string.

    Ex:-
        Input: n = 3
        Output: ["((()))","(()())","(())()","()(())","()()()"]

        Explanation:-

        ------------------------
        open: 3 close: 3 current:
         Inside first if: (
        ------------------------
        open: 2 close: 3 current: (
         Inside first if: ((
        ------------------------
        open: 1 close: 3 current: ((
         Inside first if: (((
        ------------------------
        open: 0 close: 3 current: (((
         Inside second if: ((()
        ------------------------
        open: 0 close: 2 current: ((()
         Inside second if: ((())
        ------------------------
        open: 0 close: 1 current: ((())
         Inside second if: ((()))

         Inside base case:  open 0 Close 0 Current ((()))

         Inside second if after: ((())
         Inside second if after: ((()
         Inside second if after: (((
         Inside first if after: ((
         Inside second if: (()
        ------------------------
        open: 1 close: 2 current: (()
         Inside first if: (()(
        ------------------------
        open: 0 close: 2 current: (()(
         Inside second if: (()()
        ------------------------
        open: 0 close: 1 current: (()()
         Inside second if: (()())

         Inside base case:  open 0 Close 0 Current (()())

         Inside second if after: (()()
         Inside second if after: (()(
         Inside first if after: (()
         Inside second if: (())
        ------------------------
        open: 1 close: 1 current: (())
         Inside first if: (())(
        ------------------------
        open: 0 close: 1 current: (())(
         Inside second if: (())()

         Inside base case:  open 0 Close 0 Current (())()

         Inside second if after: (())(
         Inside first if after: (())
         Inside second if after: (()
         Inside second if after: ((
         Inside first if after: (
         Inside second if: ()
        ------------------------
        open: 2 close: 2 current: ()
         Inside first if: ()(
        ------------------------
        open: 1 close: 2 current: ()(
         Inside first if: ()((
        ------------------------
        open: 0 close: 2 current: ()((
         Inside second if: ()(()
        ------------------------
        open: 0 close: 1 current: ()(()
         Inside second if: ()(())

         Inside base case:  open 0 Close 0 Current ()(())

         Inside second if after: ()(()
         Inside second if after: ()((
         Inside first if after: ()(
         Inside second if: ()()
        ------------------------
        open: 1 close: 1 current: ()()
         Inside first if: ()()(
        ------------------------
        open: 0 close: 1 current: ()()(
         Inside second if: ()()()

         Inside base case:  open 0 Close 0 Current ()()()

         Inside second if after: ()()(
         Inside first if after: ()()
         Inside second if after: ()(
         Inside first if after: ()
         Inside second if after: (
         Inside first if after:
*/

class Solution {
public:
    void generateParenthesisHelper(
         int open
        ,int close
        ,string& current
        ,vector<string>& result
    ) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if (open > 0) {
            current.push_back('(');
            generateParenthesisHelper(open - 1, close, current, result);
            current.pop_back();
        }

        if (close > open) {
            current.push_back(')');
            generateParenthesisHelper(open, close - 1, current, result);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        string current;

        generateParenthesisHelper(n, n, current, result);
        return result;
    }
};
