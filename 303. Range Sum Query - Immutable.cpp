/*
    https://leetcode.com/problems/range-sum-query-immutable/
*/
/*
    Solution Approach: Prefix Sum

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the array

    Explanation:-
        * Store the prefix sum of the array in a vector.
        * Storing prefixSum[0] = 0 as base case.
        * The prefix sum at index i is the sum of all
            elements from index 0 to i-1.
        * To get the sum of elements from index left to right,
            we can use the formula:
                sumRange(left, right) = prefixSum[right + 1] - prefixSum[left]
*/
class NumArray {
    private:
        vector<int> prefixSum;

    public:
        NumArray(std::vector<int>& nums) {
            int n = nums.size();

            prefixSum.assign(n + 1, 0);

            for (int i = 0; i < n; i++)
                prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        int sumRange(int left, int right) {
            return prefixSum[right + 1] - prefixSum[left];
        }
};

/*****************************************************************************/
/*
    Solution Approach: Using loop

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = size of the array

    Explanation:-
        * Store the array in a vector.
        * Iterate from left to right and calculate the
            sum of the elements in that range.
        * Return the sum.
*/
class NumArray {
    private:
        vector<int> arr;
    public:
        NumArray(vector<int>& nums) {
            arr = nums;
        }

        long long int sumRange(int left, int right) {
            int size = arr.size();

            long long int sum = 0;

            for(int i = left; i <= right; i++)
                sum += arr[i];

            return sum;
        }
};
