/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
/*
    Ex:- [7,1,5,3,6,4]
    Ans:- 5
    Explanation:- Buy at day 2 and sell at day 4, profit is 6 - 1 = 5

    Solution Approach:- Sliding Window Problem

    To implement this solution,
    * Store the 1st day price as min and profit as 0
    * Iterate over the array and check if the current price is less than min
        * If yes, update min
    * Else check if the profit is less than the current price - min
        * If yes, update profit
    * Else do nothing
    * Return profit
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(min > prices[i])
                min = prices[i];
            else
                if(profit < (prices[i] - min))
                    profit = prices[i] - min;
        }

        return profit;
    }
};
