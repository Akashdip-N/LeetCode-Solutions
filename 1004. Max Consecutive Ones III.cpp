/*
    https://leetcode.com/problems/max-consecutive-ones-iii/
*/
/*
    Solution Approach:- Using Sliding Window

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = number of elements in the array

    Intuition:-
        - We have to find the longest subarray of 1's such that the count of 0 is
            less than or equal to k.
        - Using sliding window technique, to keep a track of the window.
        - Storing the maximum length of the window in maxLen variable.
        - Returning the maxLen variable at the end.

    Explanation:-
        * Initialize left pointer, zeroCount and maxLen to 0.
        * Iterating through each index of the array using right pointer.
        * If the current element is 0, incrementing the count of 0's in the window.
            (To keep track of the number of 0's in the current window)
        * If the number of 0's in the window exceeds k,
            shrinking the window from the left,
                until the number of 0's in the window is less than or equal to k.
        * Updating the maxLen variable with the maximum length of the window.
            (
                i. This is specially useful for the first iteration of the window,
                ii. But when we have already found a window,
                    this time this condition is used to get the length of the maximum window.
            )
        * Returning the maxLen variable at the end.
 */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                zeroCount++;

            while (zeroCount > k) {
                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
