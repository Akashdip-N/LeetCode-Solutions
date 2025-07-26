/*
    https://leetcode.com/problems/next-permutation
*/
/*
    Solution Approach:- Two-pointer approach
    Time Complexity: O(n)
    Space Complexity: O(1)

    Explanation:
        - Traverse the array from the end to find the first decreasing element.
        - If the entire array is non-increasing,
            that means we are at the last permutation,
                so we reverse the entire array.
        - Otherwise, find the first element from the
            end that is greater than the found element.
        - Swap these two elements.
        - Finally, reverse the subarray after the first found element.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while (nums[j] <= nums[i])
            j--;

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
