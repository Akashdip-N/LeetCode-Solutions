/*
    https://leetcode.com/problems/search-in-rotated-sorted-array
*/
/*
    Binary Search Solution:

    Ex:- nums = [4,5,6,7,0,1,2], target = 0

    1. Initialize begin = 0, end = (size of the array) - 1.
    2. Iterate while begin <= end.
        a. Calculate mid = begin + (end - begin) / 2.
        b. If nums[mid] == target, return mid.
        c. If nums[begin] <= nums[mid], this means that the left half is sorted.
            i. if the target is in the left half, then will update
                end = mid - 1.
            ii. Else, the target is in the right half, so will update
                begin = mid + 1.
        d. Will check if the right half is sorted.
            i. If the target is in the right half, then will update
                begin = mid + 1.
            ii. Else, the target is in the left half, so will update
                end = mid - 1.
    3. If the target is not found, then will return -1.
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
