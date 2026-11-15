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

    Problem Statement:-
        - Given us an integer array and a target integer.
        - We need to return all the unique combinations of integers which
            sum up to the target integer.
        - We can use the same integer multiple times in the combination.

    Intuition:-
        - Using Backtracking to solve the problem.
        - We are iterating through each integer from the integer array.
        - And subtracting the integer from the target integer, and calling the function recursively.
        - If the target integer becomes 0, we found a valid combination, so we add it to the result.

    Explanation:
        * Helper function `dfs()`:-
            - Takes the following as parameters:-
                i. candidates: The input array of integers.
                ii. target: The remaining target integer we need to achieve.
                iii. start: The index from which we will start iterating through the candidates.
                iv. curr: The current combination of integers we have formed.
                v. ret: The result vector which will store all the valid combinations.
            - If the target becomes 0, that means we have found a valid combination,
                so we add the current combination to the result vector and return.

            - Iterating from the current index (i.e. start variable) till the end of the
                candidates array.
            - If the current integer is greater than the target, we are skipping that integer
                and moving to the next integer.
            - Else we push the current integer into the current combination vector and
                call the function recursively with the updated target
                    (i.e. target - candidates[i]) and
                the same index (i.e. i) to allow the same integer to be used multiple times.
            - After the recursive call, we pop the last integer from the current combination vector
                to backtrack and explore other combinations.

        * Main function `combinationSum()`:-
            - Takes the input array of integers and the target integer as parameters.
            - Initializes an empty result vector and an empty current combination vector.
            - Calls the helper function `dfs()` with the initial parameters.
            - Returns the result vector containing all the valid combinations.
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
