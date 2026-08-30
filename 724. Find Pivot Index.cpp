/*
    https://leetcode.com/problems/find-pivot-index/
*/
/*
    Solution Approach: Prefix Sum

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the array

    Intuition:-
        - We need to find the pivot index in the array such that,
            the sum of the number to the left of the index
                is equal to the sum of the numbers to the right of the index.
        - So first we store the sum of the entire array in a variable.
        - Iterate of the array to find the pivot index.
        - If none index is found, we return -1.

    Explanation:-
        * Base case:- If the array is an empty array, we return -1.

        * Storing the sum of the entire array in a variable.
        * Iterating through the entire array from index 0 til the end of the array,
            and performing the following steps:-
                - First we find the right sum by
                    subtracting the left sum and the current number from the total sum.
                - Then checking if the left sum is equal to the right sum.
                    - If yes, we return the current index as the pivot index.
                - If not, we add the current number to the left sum and
                    continue to the next index.
        * If we reach the end of the array and no pivot index is found, we return -1.
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
