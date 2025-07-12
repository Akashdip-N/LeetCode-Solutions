/*
    https://leetcode.com/problems/maximum-subarray/description/
*/
/*
    Solution Approach:- Using Kadane's Algorithm,

    Time Complexity:- O(n)
    Space Complexity:- O(1)

    Explanation:
        - We maintain two variables, max_sum and current_sum.
        - max_sum keeps track of the maximum sum found so far.
        - current_sum keeps track of the sum of the current subarray.
        - For each element in the array,
            we update current_sum to be either
                the current element
                    or
                the sum of current_sum and the current element.
        - We then update max_sum to be the maximum of itself and current_sum.
        - Finally, we return max_sum as the result.
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
