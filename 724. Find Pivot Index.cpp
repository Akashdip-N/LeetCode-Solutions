/*
    https://leetcode.com/problems/find-pivot-index/
*/
/*
    Solution Approach: Prefix Sum

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the array

    Explanation:-
        * The pivot index is the index where the sum of the numbers to the left is equal to the sum of the numbers to the right.
        * We can calculate the total sum of the array and then iterate through the array,
            keeping track of the left sum and calculating the
                right sum as total_sum - left_sum - nums[i].
        * If at any index, left_sum equals right_sum,
                we return that index as the pivot index.
        * If no such index is found, we return -1.
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int total_sum = 0;
        for (int num : nums)
            total_sum += num;

        int left_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int right_sum = total_sum - left_sum - nums[i];

            if (left_sum == right_sum)
                return i;

            left_sum += nums[i];
        }

        return -1;
    }
};
