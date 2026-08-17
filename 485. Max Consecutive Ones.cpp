/*
    https://leetcode.com/problems/max-consecutive-ones/
*/
/*
    Solution Approach:- Using Simulation

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of the input array nums

    Intuition:-
        - We have to find the count of maximum consecutive 1's in the given array nums.
        - Using two variable one to store the current count of 1's
        - Another variable to store the maximum count of 1's
        - At the end returning the maximum count of 1's

    Explanation:-
        * Intializing two variables maxCount and currentCount to 0.
        * Iterating through the input array nums.
        * If the current element is 1,
            i. Increment the currentCount
            ii. Update the maxCount if currentCount is greater than maxCount
                because later when we encounter 0, we will reset the currentCount to 0.
        * If the current element is 0, reset the currentCount to 0.
        * At the end return the maxCount which contains the max count of consecutive 1's
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;

        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            }
            else
                currentCount = 0;
        }

        return maxCount;
    }
};

/**************************************************************************************/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of the input array nums

    Intuition:-
        - Same as the previous solution,
            but instead we use two pointers to find the count.

    Explanation:-
        * Intializing maxCount and right pointer to 0.
        * Iterating from the right pointer to the end of the array nums.
        * If the current element is 1,
            i. Intializing a left pointer to the right pointer.
            (because we want to find the size of window of consecutive 1's)
            ii. We keep on moving the right pointer till we encounter 0
                or reach the end of the array.
            iii. We update the maxCount with the size of the window (right - left)
        * If the current element is 0, we just move the right pointer to the next element.
        * At the end return the maxCount which contains the max count of consecutive 1's
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int right = 0;

        while (right < nums.size()) {
            if (nums[right] == 1) {
                int left = right;
                while (right < nums.size() && nums[right] == 1)
                    right++;

                maxCount = max(maxCount, right - left);
            }
            else
                right++;
        }

        return maxCount;
    }
};
