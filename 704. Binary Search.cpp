/*
    https://leetcode.com/problems/binary-search
*/
/*
    Time Complexity:- O(log n)
    Space Complexity:- O(1)

    Solution Approach:- Binary Search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
                left = mid + 1;
            else
                if(nums[right] > target)
                    right = mid - 1;
        }

        return -1;
    }
};
