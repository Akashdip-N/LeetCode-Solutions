/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
/*
    Solution Approach:-

    Ex:- [7,1,5,3,6,4]
    Ans:- 5, becasue the best time to buy is 1 and best time to sell is 6,
             so the profit is 6-1 = 5

    To implement this solution,

    1. Initialize min = prices[0] and profit = 0
    2. Traverse the array from 1 to n
        a. If min > prices[i], which means the current price is less than the min,
            then update min = prices[i]

        b. Else, if profit < (prices[i] - min),
            which means that the
                current profit is more than the difference between the current price and min,
            then update profit = prices[i] - min
    3. Return profit
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
