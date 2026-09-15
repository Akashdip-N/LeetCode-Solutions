/*
    https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
*/
/*
    Solution Approach:- Using Mathematics

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of the input array

    Intuition:-
        - Given us a list of integers nums and an integer k.
        - We have to make sure that the sum of the array is divisible by k.
        - We can perform the following operation any number of times:
            - Choose an index i and replace nums[i] with nums[i] + 1.

        Ex:-
            nums = [3, 1, 4, 2]
            k = 6
            output = 2

            sum = 3 + 1 + 4 + 2 = 10 => 10 % 6 = 4
            So, if we change the value of
            nums[0] = 3 + 1 = 4 => sum = 11 => 11 % 6 = 5
            nums[1] = 1 + 1 = 2 => sum = 12 => 12 % 6 = 0
            So, we need to perform 2 operations

        - But thinking oppositely this is same as finding,
            if the sum of the array is divisible by k or not.
        - If not then by how much do we need to make it divisible by k.
        - So we find the sum of the array and then
            return the remainder of the sum when divided by k.
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        for(int num: nums)
            sum += num;

        return sum % k;
    }
};
