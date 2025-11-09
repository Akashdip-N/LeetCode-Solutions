/*
    https://leetcode.com/problems/binary-watch
*/
/*
    Solution Approach:- Using Bit Manipulation

    Time Complexity: O(1)
    Space Complexity: O(1)

    Explanation:
        * Using two nested loops to iterate through all possible
            hours (0-11) and minutes (0-59).
        * Using __builtin_popcount to count the number of 1's in the binary
            representation of the hour and minute,
                and checking if their sum equals turnedOn.
        * If it matches, formatting the time string and adding it to the result list.
        * Finally, returning the result list.
*/
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string hour = to_string(h);
                    string minute;

                    if (m < 10)
                        minute = "0" + to_string(m);
                    else
                        minute = to_string(m);

                    string timeStr = hour + ":" + minute;
                    result.push_back(timeStr);
                }
            }
        }

        return result;
    }
};
