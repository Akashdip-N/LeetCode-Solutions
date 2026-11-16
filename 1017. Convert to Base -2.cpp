/*
    https://leetcode.com/problems/convert-to-base-2/
*/
/*
    Solution Approach:- Using Simulation

    Time Complexity: O(log N)
    Space Complexity: O(log N)
    N = numbers present in the input (n)

    Problem Statement:-
        - Given an integer n, return a binary string representing its representation in base -2.
        - The returned string must not have leading zeros unless the string is "0".
*/
class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string res = "";

        while (n != 0) {
            int rem = n % (-2);

            if (rem < 0) {
                rem += 2;
                n = (n - rem) / (-2);
            } else
                n /= -2;

            res += char('0' + rem);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
