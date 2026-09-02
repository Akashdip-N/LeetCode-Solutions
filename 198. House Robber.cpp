/*
    https://leetcode.com/problems/house-robber/
*/
/*
    Solution Approach:- Using Dynamic Programming

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of the input array

    Intuition:-
        - We have to rob houses along a street, but we can't rob two adjacent houses.
        - We have to return the maximum amount of money we can rob without alerting the police.
        - Using dynamic programming approach,
            i. Either we can start from the first house or the second house,
            ii. So what we would do is, we would use two variables to keep track of the
                    maximum amount of money we can rob.
            iii. And for each house, we would check if we rob that house or not,
                    and we would update the maximum amount of money we can rob accordingly.
        - At the end return the maximum amount of money we can rob.

    Explanation:-
        * Intializing two variables rob1 and rob2 to 0,
            which will keep track of the maximum amount of money we can rob.
        * Iterating through each house in the input array,
            - For each house, adding the amount of money in that house to rob1,
                and checking if it's greater than rob2 or not.
            - If it's greater than rob2, then we update rob2 to that value,
                else we keep rob2 as it is.
        * At the end return rob2, which will be the maximum amount of money we can rob.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for(int num: nums){
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};
