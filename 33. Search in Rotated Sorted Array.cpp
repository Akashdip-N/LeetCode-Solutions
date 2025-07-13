/*
    https://leetcode.com/problems/search-in-rotated-sorted-array
*/
/*
    Solution Approach: Binary Search

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Explanation:
        - Comparing the middle element with the target.
        - If the left half is sorted,
            check if the target is in that range,
                then adjust the right pointer with `mid - 1`.
                else adjust the left pointer with `mid + 1`.
        - If the right half is sorted,
            check if the target is in that range.
                then adjust the left pointer with `mid + 1`.
                else adjust the right pointer with `mid - 1`.
        - Adjust the search range accordingly.
        - Return the index if found, otherwise return -1.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0, left = 0, right = nums.size() - 1;

        while(left <= right) {
            mid = left + (right - left) / 2;

            if(nums[mid] == target)
                return mid;

            // Check if the left half is sorted
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
