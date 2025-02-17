/*
    https://leetcode.com/problems/missing-number/
*/
/*
    Summation Solution Approach:-

    To implement this solution:-
    1. Calculate the sum from 0 to n(size of the array)
    2. Traverse the array
        a. Subtract the current element from the sum
    3. Return the sum, which will the missing number
*/
class Solution {                                // Time Complexity: O(n)
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size * (size + 1) / 2;        // O(1)
        for(auto i : nums)
            sum -= i;
        return sum;
    }
};

/*
    Sorting Solution Approach:-

    To implement this solution:-
    1. Sort the array
    2. Traverse the array
        a. If the current element is not equal to the index,
            then return the index
    3. Return the size of the array
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++)
            if(nums[i] != i)
                return i;

        return size;
    }
};
