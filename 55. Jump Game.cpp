/*
    https://leetcode.com/problems/jump-game
*/
/*
    Solution Approach: Using Greedy Algorithm

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:

        ( The main target of this problem is to reach to the 0th index)

        - We are starting from the last index and moving inwards.
        - We maintain a variable `goal` which represents the last index we
            can reach.
        - For each index, if we can reach the `goal` from that index (i.e.,
            if `i + nums[i] >= goal`), we update `goal` to that index.
        - If we can reach the first index (i.e., `goal` becomes 0), we return true.
        - If we finish the loop and `goal` is not 0, we return false.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= goal)
                goal = i;
        }

        return goal == 0;
    }
};

/**********************************************************************************/
/*
    Solution Approach: Alternative Greedy Approach

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:

        (The main target of this problem is to reach the last index)

        - For this problem we are starting the first index and moving forward.
        - We store the maximum reachable index in a variable `maxReachable`.
        - For each index, we check if we can reach it from the previous indices.
        - If we can reach the current index, we update `maxReachable` to
            the maximum of its current value and the index plus the jump length.
        - If at any point `maxReachable` reaches or exceeds the last index,
            we return true.
        - If we finish the loop and `maxReachable` is less than the last index,
            we return false.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > maxReachable)
                return false;

            maxReachable = max(maxReachable, i + nums[i]);

            if (maxReachable >= n - 1)
                return true;
        }

        return false;
    }
};


/************************* TIME COMPLEXITY NOT GOOD *******************************/
/*
    Alternative Approach: Using Dynamic Programming

    Time Complexity: O(n^2)
    Space Complexity: O(n)
    n = length of the input array

    Explanation:
        - We create a boolean array `dp` where `dp[i]` indicates whether
            we can reach index `i` from the start.
        - We initialize `dp[0]` to true since we can always start at index 0.
        - For each index, we check all previous indices to see if we can
            jump to the current index.
        - If we can reach the current index from any previous index, we set
            `dp[i]` to true.
        - Finally, we return the value of `dp[n-1]`, which indicates whether
            we can reach the last index.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (dp[j] && j + nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
        }

        return dp[n - 1];
    }
};
