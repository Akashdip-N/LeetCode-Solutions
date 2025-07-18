/*
    https://leetcode.com/problems/squares-of-a-sorted-array
*/
/*
    Solution Approach: Two Pointer Approach

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = length of the input array

    Explanation:
        - We have a sorted array that can contain both negative and positive integers.
        - We need to return an array of the squares of each number,
            sorted in non-decreasing order.
        - We can use two pointers:
            i. `left` pointer starting from the beginning of the array
            ii. `right` pointer starting from the end of the array
        - We compare the absolute values at both pointers:
            - If the absolute value at `left` is greater,
                we square it and place it at the end of the result.
            - If the absolute value at `right` is greater,
                we square it and place it at the end of the result.
        - We continue this until all elements are processed.
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();

        if(size == 1)
            return {nums[0] * nums[0]};

        vector<int> result(size);
        int left = 0, right = size - 1;

        for(int i = size - 1; i >= 0; --i) {
            if(abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};
