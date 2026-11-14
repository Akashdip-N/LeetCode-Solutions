/*
    https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
*/
/*
    Solution Approach:- Using Array Traversal

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input array

    Intuition:-
        - Given us an integer array nums.
        - We need to find the length of the longest strictly increasing or
            strictly decreasing subarray.

        - While iterating through the array, we would keep track of the following:-
            1. The length of the current increasing subarray.
            2. The length of the current decreasing subarray.
            3. The maximum length of the increasing or decreasing subarray.
        - At the end we would return the maximum length stored in the variable.

    Explanation:-
        * Base case:- If the array is empty, we return 0.

        * Initializing the Maximum Length, Increasing Length, and Decreasing Length to 1.
        * Iterating through index 1 till the end of the array,
            and performing the following checks:-
            i. If the current element is greater than the previous element,
                that means we are in the increasing subarray,
                    so we increment the increasing length and reset the decreasing length to 1.
            ii. If the current element is less than the previous element,
                that means we are in the decreasing subarray,
                    so we increment the decreasing length and reset the increasing length to 1.
            iii. If the current element is equal to the previous element,
                that means we are not in any subarray,
                    so we reset both the increasing and decreasing lengths to 1.
        * At the end of each iteration,
            we update the maximum length with the maximum of the
                current maximum length, increasing length, and decreasing length.
        * Finally, we return the maximum length stored in the variable.
*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLen = 1;
        int inc = 1;
        int dec = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }

            maxLen = max({maxLen, inc, dec});
        }

        return maxLen;
    }
};
