/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
/*
    Solution Approach: Two Pointer Approach

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of prices array

    Explanation:
        i. Store the first element of prices array in min variable.
        ii. Store 0 in profit variable.
        iii. Iterate through the prices array starting from index 1.
        iv. If the current element is less than min, update min to current element.
        v. Else, if the difference between current element and
            min is greater than profit, update profit to the difference.
        vi. Finally, return profit.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(min > prices[i])
                min = prices[i];
            else
                if(profit < (prices[i] - min))
                    profit = prices[i] - min;
        }

        return profit;
    }
};
