/*
    https://leetcode.com/problems/sort-colors
*/
/*
    Solution Approach: Two Pointer Approach

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:
        - We have only three colors represented by 0, 1, and 2.
        - We have to make sure that
            i. All 0s come first
            ii. All 1s come in the middle
            iii. All 2s come last
        - We can use three pointers:
            i. `left` pointer to track the position of the next 0
            ii. `right` pointer to track the position of the next 2
            iii. `i` pointer to traverse the array
        - We iterate through the array:
            - If the current element is 0,
                we bring it to the front of the array.
            - If the current element is 2,
                we bring it to the end of the array.
            - If the current element is 1, we simply move to the next element.
        - This way, we ensure that the array is sorted in a single pass.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, i = 0;

        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else
                i++;
        }
    }
};
