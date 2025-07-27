/*
    https://leetcode.com/problems/jump-game-ii
*/
/*
    Solution Approach: Using Greedy Algorithm

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:-
        - Starting from the first index and moving forward.
        - Set the count variable, left and right pointer to 0.
        - Traverse from left(0th index) till the end of the nums array.
        - For each index, calculate the maximum reachable index from the current range.
            i.e., which index can be reached from the current index.
        - Update the left pointer to the next index after the current range.
        - Update the right pointer to the maximum reachable index.
        - Increment the count for each jump made.
        - Repeat until the right pointer reaches or exceeds the last index.
        - Return the count of jumps made.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int l = 0, r = 0;

        while (r < nums.size() - 1) {
            int maxReach = 0;

            for (int i = l; i <= r; ++i)
                maxReach = max(maxReach, i + nums[i]);

            l = r + 1;
            r = maxReach;
            count++;
        }

        return count;
    }
};
