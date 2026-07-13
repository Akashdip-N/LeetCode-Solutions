/*
    https://leetcode.com/problems/fruit-into-baskets/
*/
/*
    Solution Approach:- Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1) (It's constant because the maximum number of fruit types is 2)
    N = length of the input array

    Explanation:-
        * Using HashMap to store the count of each fruit type in the current window.
        * Initialize two pointers, left and right, to represent the current window.
        * If the current window size is greater than 2,
            then we decrement the count of the left fruit type
            and when the count becomes 0,
                we remove it from the HashMap and move the left pointer to +1 pos to the right.
        * Update the maximum number of fruits collected in the current window.
        * Return the maximum number of fruits collected.
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        int left = 0;
        unordered_map<int, int> count;

        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;

            while (count.size() > 2) {
                count[fruits[left]]--;

                if (count[fruits[left]] == 0)
                    count.erase(fruits[left]);

                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};
