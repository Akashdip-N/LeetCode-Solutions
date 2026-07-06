/*
    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
/*
    Solution Approach:- Binary Search (Using Greedy Approach)
                        (This problem is kind of same as Pr. 875. Koko Eating Bananas)

    Time Complexity: O(N * logM)
    Space Complexity: O(1)

    N = number of weights
    M = sum of weights

    Explanation:-
        * The problem is to find the minimum capacity of the ship to ship all packages within D days.
        * We can use binary search to find the minimum capacity.
        * The minimum capacity of the ship is the maximum weight of a package,
            and the maximum capacity is the sum of all weights.
        * This would be our search space for the binary search.
        * We can use a greedy approach to check if we can ship all packages within D days with a given capacity.
*/
class Solution {
private:
    bool canShip(const vector<int>& weights, int midCap, int days) {
        int daysUsed = 1;
        int currentLoad = 0;

        for (int weight : weights) {
            if ((currentLoad + weight) > midCap) {
                daysUsed++;
                currentLoad = 0;
            }

            currentLoad += weight;
        }

        return daysUsed <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 0;
        int maxCap = 0;

        for (int weight : weights) {
            minCap = max(minCap, weight);
            maxCap += weight;
        }

        int ans = maxCap;

        while (minCap <= maxCap) {
            int midCap = minCap + (maxCap - minCap) / 2;

            if (canShip(weights, midCap, days)) {
                ans = midCap;
                maxCap = midCap - 1;
            } else
                minCap = midCap + 1;
        }

        return ans;
    }
};
