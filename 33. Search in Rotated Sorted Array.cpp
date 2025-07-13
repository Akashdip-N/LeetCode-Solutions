/*
    https://leetcode.com/problems/search-in-rotated-sorted-array
*/
/*
    Solution Approach: Binary Search

    Time Complexity: O(log n)
    Space Complexity: O(1)

    Explanation:
        - Comparing the middle element with the target.
        - If the left half is sorted, check if the target is in that range.
        - If the right half is sorted, check if the target is in that range.
        - Adjust the search range accordingly.
        - Return the index if found, otherwise return -1.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0, begin = 0, end = nums.size() - 1;
        while(begin <= end) {
            mid = begin + (end - begin) / 2;

            if(nums[mid] == target)
                return mid;

            if(nums[begin] <= nums[mid])
                if(target >= nums[begin] && target < nums[mid])
                    end = mid - 1;
                else
                    begin = mid + 1;
            else
                if(target > nums[mid] && target <= nums[end])
                    begin = mid + 1;
                else
                    end = mid - 1;
        }
        return -1;
    }
};
