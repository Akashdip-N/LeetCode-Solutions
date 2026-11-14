/*
    https://leetcode.com/problems/rotate-string/
*/
/*
    Solution Approach:- Using String Concatenation

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = length of the input string

    Intuition:-
        - Given us a string (s) and another string (goal).
        - We need to check if by any number of shifts of string (s),
            we can make it equal to string (goal).
        - Shift means:- s = "abcde" -> shift 1 -> "bcdea" -> shift 2 -> "cdeab"

        - Using string concatenation to solve this problem.
        - For each index of string (s),
            we are concatenating the substring from that index till the end of the string
                with the substring from the start of the string till that index.
        - Then we are checking if the concatenated string is equal to string (goal).

    Explanation:-
        * Base Case:-
            i. If the size of the two strings are not equal, then we return false.
            ii. If the two strings are equal, then we return true.

        * Iterating from the 1st index till the end of the string (s).
        * Performing the following operation for each index (i):-
            - Concatenating the substring from index (i) till the end of the string (s)
                with the substring from the start of the string (s) till index (i).
            - Checking if the concatenated string is equal to string (goal).
            - If it is equal, then we return true.
        * If we have iterated through the entire string (s) and not found any match,
            then we return false.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        if(s == goal) return true;

        for(int i = 1; i < s.size(); i++)
            if((s.substr(i) + s.substr(0, i)) == goal)
                return true;

        return false;
    }
};

/******************************************************************************************/
/*
    Solution Approach:- Using String Concatenation (Optimized)

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = length of the input string

    Intuition:-
        - Same as the previous approach, but optimized.

        - Since, it's a circular shift, that means,
            if we concatenate the string (s) with itself,
                then the string (goal) should be a substring of the concatenated
                    string (s + s).

    Explanation:-
        * Checking the following conditions:-
            i. If the size of the two strings are equal or not.
            ii. If the string (goal) is a substring of the concatenated string (s + s).
        * If both the conditions are true, then we return true.
        * Otherwise, we return false.
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};
