/*
    https://leetcode.com/problems/sum-of-squares-of-special-elements/
*/
/*
    Solution Approach:- Using Iterative Approach

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = Size of the array

    Intuition:-
        - Given us an integer array.
        - We have to find the sum of squares of the numbers which are following
            this condition that is,
        - The index is able to divide the size of the array.
        - We have to follow 1 based indexing for the index, but the array is 0 based indexing.

        - At the end we return the sum of squares of the special elements.

    Explanation:-
        * Initializing the return variable to 0.
        * Storing the size of the array in a variable.
        * Iterating from index (0) till the end of the array i.e. size - 1,
            and checking the following condition for each index,
                if the size of the array is divisible by the index + 1,

                    **************************************************
                    *  The reason we are doing index + 1 because
                    *  the index is 0 based but we have to consider it as
                    *  1 based for the condition.
                    **************************************************

                then we add the square of the element at that index to the return variable.
        * At the end of the iterations, we return the return variable as the result.
*/
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();

        for(int i = 0; i < size; i ++)
            if(size % (i + 1) == 0)
                ret += nums[i]*nums[i];

        return ret;
    }
};
