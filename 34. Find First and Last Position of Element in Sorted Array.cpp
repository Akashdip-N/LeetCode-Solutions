/*
    https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/
/*
    Solution Approach:- Using Binary Search

    Time Complexity:- O(logN) (Since we are using binary search)
    Space Complexity:- O(1)
    N = size of the input array

    Intuition:-
        - Given us ascending orderly sorted integer array and a target value.
        - We have to find the starting and the ending index of the target value in the array.

        - Using binary search to find the two indices of the target value in the array.
        - Using a helper function to perform the binary search
            for the left and the right subhalf of the array.
        - First we are searching the left subhalf of the array
            then we are searching the right subhalf of the array
                to find the index of the target value.

    Explanation:-
        * Helper function (integer array, target value, boolean value):-
            - This function is performing the binary search,
                but the only catch is if we want to find the left index of the target value
                    then we would set the boolean value to true
                        and if we want to find the right index of the target value
                            then we would set the boolean value to false.
        * Main function:-
            - Calling the helper function twice to find the left and the right index
                and returning the result as a vector of two integers.
*/
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftbias){
        int left = 0, right = nums.size() - 1;
        int i = -1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(target > nums[mid])
                left = mid + 1;
            else if(target < nums[mid])
                right = mid - 1;
            else{
                i = mid;
                if(leftbias)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return i;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        return {left, right};
    }
};
