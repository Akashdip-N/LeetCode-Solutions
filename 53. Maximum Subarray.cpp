/*
    https://leetcode.com/problems/maximum-subarray/description/

    Time Complexity:- O(n), Space Complexity:- O(1)

    Approach:- Using Kadane's Algorithm
        * Iterating from the second element to the last element of the array.
        * Updating the current sum based on greater in value of the,
            current element
                or
            sum of the current element and the previous sum.
        * Updating the max_sum,
            based on the maximum of the current sum and the max_sum.
        * Finally returning the max_sum.
*/
/*
    For better understanding:-
        https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
