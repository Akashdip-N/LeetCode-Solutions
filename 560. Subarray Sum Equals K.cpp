/*
    https://leetcode.com/problems/subarray-sum-equals-k
*/
/*
    Solution Approach:- Using HashMap and Prefix Sum

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the input array

    Intuition:-
        - We have to find the number of subarrays that can be made out of the given array
            such that the sum of the elements in the subarray is equal to K.
        - Using prefix sum, technique to find the subarrays that sum to K can be optimized.
        - For each number we adding to the current sum,
            we check if have seen a prefix sum that is equal to currentSum - K.
                If yes, then we add the count of that prefix sum to the total count of subarrays.
        - At the end we return the total count of subarrays that sum to K.

    Explanation:
        * Storing the value of 1 at index 0 in the hash map because,
            then we can consider the subarray from the start of the array to the current index.
            (
                Ex:-
                    nums = [3, 2, 1]
                    K = 3

                    Iteration 1:
                        currentSum = 3
                        currentSum - K = 0
                        count += prefixSumCount[0] = 1
            )
        * Iterating through each number in the array and adding it to the current sum,
            and performing the following steps:-
            - Adding the current num to the current sum.
            - Checking if the current sum - K exists in the hash map,
                if yes, then we add the count of that prefix sum to the total count of subarrays.
            - Finally, we increment the count of the current sum in the hash map.
            (
                Ex:-
                    nums = [3, 2, 1]
                    K = 3

                    Iteration 1:
                        currentSum = 3
                        currentSum - K = 0
                        count += prefixSumCount[0] = 1
                        prefixSumCount[3] = 1

                    Iteration 2:
                        currentSum = 5
                        currentSum - K = 2
                        count += prefixSumCount[2] = 0
                        prefixSumCount[5] = 1

                    Iteration 3:
                        currentSum = 6
                        currentSum - K = 3
                        count += prefixSumCount[3] = 1
                        prefixSumCount[6] = 1

                    Count = 2
            )
        * Finally, we return the total count of subarrays that sum to K.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;

            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end())
                count += prefixSumCount[currentSum - k];

            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
