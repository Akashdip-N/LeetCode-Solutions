/*
    https://leetcode.com/problems/subarray-sum-equals-k
*/
/*
    Solution Approach:- Using Prefix Sum and Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = size of the input array

    Explanation:
        - We maintain a running sum of the elements in the array.
        - We use a hash map to store the count of each prefix sum encountered.
        - For each element, we check
            if the difference between the current sum and
                k exists in the hash map.
        - If it does, it means there are subarrays that sum to k.
        - We update the count of the current prefix sum in the hash map.
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
