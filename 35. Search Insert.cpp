/*
    https://leetcode.com/problems/search-insert-position/
*/
/*
    Solution:

    Implement binary search to find the target element.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
