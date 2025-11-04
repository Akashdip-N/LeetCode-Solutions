/*
    https://leetcode.com/problems/permutations
*/
/*
    Solution Approach: Backtracking

    Time Complexity: O(N!)
    Space Complexity: O(N)
    N = number of elements in the input array

    Explanation:
        * Using a function backtrack to generate permutations recursively.
        * Traversing through each number in the input array.
        * If the number is already visited, skip it.
        * Else, mark the number as visited and add it to the current permutation.
        * Recursively call backtrack to continue building the permutation.
        * If the current permutation size equals the input array size, add it to the result.
        * After exploring, backtrack by unmarking the number and
            removing it from the current permutation.
        * Finally, return the result containing all permutations.
*/
class Solution {
public:
    void backtrack(
        const vector<int>& nums,
        vector<bool>& visited,
        vector<int>& currentPermutation,
        vector<vector<int>>& result
    ) {
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

            visited[i] = true;
            currentPermutation.push_back(nums[i]);

            backtrack(nums, visited, currentPermutation, result);

            visited[i] = false;
            currentPermutation.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, visited, currentPermutation, result);

        return result;
    }
};
