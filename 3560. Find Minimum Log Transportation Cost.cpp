/*
    https://leetcode.com/problems/find-minimum-log-transportation-cost/description/
*/
/*
    Time & Space Complexity:- O(1)

    Approach:-
    * Calculate and store the cost of cutting the logs,
        using the formula:
            total_cost = total_cost + (log_size - size_of_truck) * size_of_truck
    * Return the total cost.
*/
class Solution {
public:
    long long minCuttingCost(int n, int m, int64_t k) {
        int64_t cost = 0;

        if(n > k)
            cost += (n-k)*k;

        if(m > k)
            cost += (m-k)*k;

        return cost;
    }
};
