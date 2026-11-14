/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
/*
    Solution Approach: Two Pointer Approach

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = size of prices array

    Intuition:-
        - Given us an array prices, where prices[i] is the price of the stock on the ith day.
        - We need to find the maximum profit we can achieve by buying and selling the stock.
        - We can only buy and sell the stock once.

        - Using two pointers approach, to solve this problem.
        - First checking which day has the minimum price,
            and then checking which day has the maximum price after that day.

    Explanation:-
        * Initializing the minimum price to the first element of the array.
        * Setting the profit to 0.
        * Iterating from the 1st index to the end of the array,
            and performing the following operation:-
            - If the current stock price is less than the minimum price,
                we update the minimum price to the current stock price.
            - Else, we check if current profit is less than
                the difference between the current stock price and the minimum price,
            - Then we update the profit with the difference between the
                current stock price and the minimum price.
        * At the end we return the profit which we have calculated.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(min > prices[i])
                min = prices[i];
            else if(profit < (prices[i] - min))
                    profit = prices[i] - min;
        }

        return profit;
    }
};
