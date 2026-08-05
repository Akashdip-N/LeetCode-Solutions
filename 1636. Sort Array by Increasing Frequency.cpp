/*
    https://leetcode.com/problems/sort-array-by-increasing-frequency/
*/
/*
    Solution Approach:- Using Hash Map and Custom Sorting

    Time Complexity:- O(NlogN)
    Space Complexity:- O(N)
    N = length of nums

    Intuition:-
        - We have to sort the elements in the nums,
            either based on their frequency or their value (low values comes first),
                and if there is a tie in the frequency,
                    then we have to sort the elements based on their value (high values comes first).
        - Using Hash Map to store the frequency of each element in the nums array.
        - Then sorting the nums array based on the frequency and value of the elements.

    Explanation:-
        * Storing the frequency of each element in the nums array in the Hash Map.
        * Then sorting the nums array and using a custom function to
            first check if their frequence are different or same,
                - if the frequency are different then
                    sort the elements based on their frequency (low frequency comes first),
                - if the frequency are same then
                    sort the elements based on their value (high value comes first).
        * At the end return the sorted nums array.
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums)
            m[num]++;

        sort(nums.begin(), nums.end(), [m&](int a, int b) {
            if (m[a] != m[b])
                return m[a] < m[b];

            return a > b;
        });

        return nums;
    }
};
