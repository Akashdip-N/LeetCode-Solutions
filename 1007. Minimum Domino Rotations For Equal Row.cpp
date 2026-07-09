/*
    https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/
/*
    Solution Approach:- Greedy Approach

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of either of the array i.e. tops or bottoms

    Explanation:-
        * First taking the first element of both top and bottom array.
        * Iterating through the entire array,
            and checking if the current element is equal to the target or not.
        * If the top element is equal to the target,
            then we increment the top counter,
                else we increment the bottom counter.
        * If the current element is not equal to the target,
            then we break the loop and return the minimum of the two counters.
        * If none of the targets are valid, then we return -1.
*/
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int targets[2] = {tops[0], bottoms[0]};

        for (int target : targets) {
            int missingT = 0;
            int missingB = 0;
            bool is_valid = true;

            for (int i = 0; i < n; i++) {
                int top = tops[i];
                int bottom = bottoms[i];

                if (top != target && bottom != target) {
                    is_valid = false;
                    break;
                }

                if (top != target)
                    missingT++;

                if (bottom != target)
                    missingB++;
            }

            if(is_valid)
                return min(missingT, missingB);
        }

        return -1;
    }
};
