/*
    https://leetcode.com/problems/search-in-rotated-sorted-array
*/
/*
    Solution Approach: Using Binary Search

    Time Complexity: O(log N)
    Space Complexity: O(1)
    N = Length of the array nums

    Intuition:-
        * Since the array is sorted in ascending order, we would use binary search to find the target value.
        * But, since the array is rotated, we need to check which halves does our target value lies in.
        * If element found return the index of the element, else return -1.

    Explanation:-
        * Initialize left and right pointers to the start and end of the array.
        * While left pointer is less than or equal to right pointer, do the following:
            * Find the mid index of the array.
            * If the element at mid index is equal to the target value, return the mid index
            * Then we check if the left half of the array is in ascending or not,
                then we check if the left value is less than or equal to the mid value,
                    that means the left half is in ascending order.
                * Then we check if the target value lies in the left half of the array,
                    if it does,
                        we move the right pointer to mid - 1
                    else,
                        we move the left pointer to mid + 1
            * If the left half is not in ascending order, then the right half must be in descending order.
                * Then we check if the target value lies in the right half of the array,
                    if it does,
                        we move the left pointer to mid + 1
                    else,
                        we move the right pointer to mid - 1
        * If we reach the end of the while loop,
            that means the target value is not present in the array, so we return -1.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0, left = 0, right = nums.size() - 1;

        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;

            // Left side is in ascending order
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else // Right side is in descending order
            {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};
