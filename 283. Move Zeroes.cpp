/*
    https://leetcode.com/problems/move-zeroes/
*/
/*
    Solution Approach: Using Two Pointers / In-Place Swapping

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input array

    Intuition:-
        - Given us a integer array nums.
        - We need to move all the 0's to the end of the array,
            while maintaining the relative order of the non-zero elements.

        - Using two-pointers approach, to solve this problem
        - Instead of moving all the 0's to the end,
            we are moving all the non-zero elements to the front of the array
                and then filling the rest of the array with 0's.

    Explanation:-
        * Setting the left pointer to 0
        * Iterating from the 0th index to the end of the array
        * If the current element is non-zero,
            we swap it with the element at the left pointer & increment the left pointer by 1.

        - Ex:-
            Input: nums = [0, 1, 0, 3, 12]
            Output: [1,3,12,0,0]

            Iteraiton 1:-
                l = 0, i = 0
                nums[i] = 0, so we do nothing
                nums = [0, 1, 0, 3, 12]

            Iteraiton 2:-
                l = 0, i = 1
                nums[i] = 1, so we swap nums[l] and nums[i]
                nums = [1, 0, 0, 3, 12]
                l = 1, i = 1

            Iteraiton 3:-
                l = 1, i = 2
                nums[i] = 0, so we do nothing
                nums = [1, 0, 0, 3, 12]

            Iteraiton 4:-
                l = 1, i = 3
                nums[i] = 3, so we swap nums[l] and nums[i]
                nums = [1, 3, 0, 0, 12]
                l = 2, i = 3

            Iteraiton 5:-
                l = 2, i = 4
                nums[i] = 12, so we swap nums[l] and nums[i]
                nums = [1, 3, 12, 0, 0]

        * At the end we exit out of the loop and the array is modified in-place.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[l], nums[i]);
                l++;
            }
        }
    }
};
