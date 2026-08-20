/*
    https://leetcode.com/problems/longest-increasing-subsequence/
*/
/*
    Solution Approach:- Using Dynamic Programming (Bottom-Up) with Tabulation Approach

    Time Complexity: O(N*N)
    Space Complexity: O(N)
    N = size of the input vector

    Intuition:-
        - We have to find a subsequence of a given sequence,
            such that all elements of the subsequence are sorted in increasing order.
        - A subsequence is where we can delete some or no elements without
            changing the order of the remaining elements.
        - We can find how many possible ways can we form a subsequence from
            the current element and the elements after it.

        Ex:-
            Input: nums = [1,2,4,3]
            Output: 3, the subsequence is [1,2,3] or [1,2,4]

            From index 0, how many possible ways we can form a subsequence:-
                 1 < 2, so we can form a subsequence [1,2]
                 1 < 4, so we can form a subsequence [1,4]
                 1 < 3, so we can form a subsequence [1,3]
            the answer is 3

            From index 1, how many possible ways we can form a subsequence:-
                 2 < 4, so we can form a subsequence [2,4]
                 2 < 3, so we can form a subsequence [2,3]
            the answer is 2

            From index 2, how many possible ways we can form a subsequence:-
                 4 < 3, so we can't form a subsequence
            the answer is 1, i.e. the subsequence is [4]

            From index 3, how many possible ways we can form a subsequence:-
                 3 is the last element, so we can't form a subsequence
            the answer is 1, i.e. the subsequence is [3]

    Explanation:-
        * Initializing a vector to store the length of the possible subsequence
            from the current index to the end of the vector.
        * Iterating through the vector from the 2nd last index to the beginning.
            (
                Because the last element will always have a subsequence of length 1
                i.e. itself.
            )
        * For each index after the current index,
            if the next element is greater than the current element,
                that means we can form a subsequence from the current index to the next index.
                    then we store the length of the subsequence
                        that can be formed from the current index to the end of the vector.
                Using the formula: 1 + (length of the subsequence from the next index)
        * Finally, returning the maximum element from the vector,
            which will be the length of the longest increasing subsequence.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> memo(size, 1);

        for(int i = size - 2; i >= 0; i--)
            for(int j = i + 1; j < size; j++)
                if(nums[i] < nums[j])
                    memo[i] = max(memo[i], 1 + memo[j]);

        return *max_element(memo.begin(), memo.end());
    }
};


/*******************************************************************************************/
/*
    Solution Approach:- Using Dynamic Programming (Bottom-Up) with Memoization Approach

    Time Complexity: O(N*N)
    Space Complexity: O(N)
    N = size of the input vector

    Intuition:-
        - Same as the previous approach, but instead calling the function recursively.
        - Using a hash map to store the length of the possible subsequence
            from the current index to the end of the vector.
*/
class Solution {
public:
    int dfs(
        unordered_map<int, int>& memo,
        vector<int>& nums,
        int i
    ){
        if (memo.count(i))
            return memo[i];

        int maxLen = 1;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[j] > nums[i])
                maxLen = max(maxLen, 1 + dfs(memo, nums, j));

        return memo[i] = maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> memo;

        for (int i = nums.size() - 2; i >= 0; i--)
            maxLength = max(maxLength, dfs(memo, nums, i));

        return maxLength;
    }
};
