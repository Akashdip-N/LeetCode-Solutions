/*
    https://leetcode.com/problems/combination-sum/
*/
/*
    Solution Approach:- Backtracking and DFS

    Time Complexity:- O(N^(T/M + 1))
    Space Complexity:- O(T/M)

    N = number of candidates
    T = target
    M = minimum value in candidates

    Explanation:
        * Creating a function dfs to perform depth first search and backtracking.
        * Base case:
            - If target is 0, we found a valid combination, so we add it to the result.
        * Else loop through candidates starting from 'start' index:
            - If the candidate is greater than target, skip it.
            - Else, add the candidate to current combination and call dfs with reduced target.
            - After returning from dfs, remove the last added candidate (backtrack).
        * Finally, return the result containing all valid combinations.
*/
class Solution {
public:
    void dfs(
        vector<int>& candidates,
        int target,
        int start,
        vector<int>& curr,
        vector<vector<int>>& ret
    ) {
        if (target == 0){
            ret.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++){
            if (candidates[i] > target)
                continue;

            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, curr, ret);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curr;

        dfs(candidates, target, 0, curr, ret);
        return ret;
    }
};
