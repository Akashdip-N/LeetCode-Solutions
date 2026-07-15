/*
    https://leetcode.com/problems/split-array-largest-sum/
*/
/*
    Solution Approach:- Using Binary Search + Greedy

    Time Complexity:- O(N * log(S))
    Space Complexity:- O(1)
    N = number of elements in the array
    S = sum of all elements in the array

    Explanation:-
        * We have to find the subarray such that the sum of the subarray is minimized
            and have the whole array split into k subarrays.
        * Using binary search to find the scope the problem in such a way that,
            * Setting left pointer to the maximum value element in the array.
            * Setting right pointer to the sum of all elements in the array.
        * Using a while loop to perform binary search until left pointer is less than or equal to right pointer.
            * Calculate the mid value of the left and right pointers.
            * Check if we can split the array into k subarrays with the largest sum less than or equal to mid.
                * If we can split, then we can try to minimize the largest sum by moving the right pointer to mid - 1.
                * If we cannot split, then we need to increase the largest sum by moving the left pointer to mid + 1.
        * Return the left pointer as the answer.

    Example:-
        Input: nums = [7,2,5,10,8], k = 2
        Output: 18

        Iteration 1:-
            left = 10, right = 32, mid = 21
            canSplit(nums, 21, 2) = true
            right = 20

        Iteration 2:-
            left = 10, right = 20, mid = 15
            canSplit(nums, 15, 2) = false
            left = 16

        Iteration 3:-
            left = 16, right = 20, mid = 18
            canSplit(nums, 18, 2) = true
            right = 17

        Iteration 4:-
            left = 16, right = 17, mid = 16
            canSplit(nums, 16, 2) = false
            left = 17

        Iteration 5:-
            left = 17, right = 17, mid = 17
            canSplit(nums, 17, 2) = false
            left = 18

        Final Answer:-
            left = 18, right = 17
*/
class Solution {
public:
    bool canSplit(vector<int>& nums, int largest, int k) {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= largest)
                currentSum += num;
            else {
                subarrayCount++;
                currentSum = num;
            }
        }

        return subarrayCount <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        for (int num : nums) {
            left = max(left, num);
            right += num;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canSplit(nums, mid, k))
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};
