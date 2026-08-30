/*
    https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
*/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity:- O(N)
    Space Complexity:- O(1) (Excluding the space for the output array)
    N = input integer n

    Intuition:-
        - Given n, we have to construct an array of n unique integers,
            such that the sum of all the integers in the array is equal to 0.
        - So what we would do is,
            using two pointers, we would start from the middle of the array,
                and move to both directions, filling the array with unique integers,
                    such that the sum of all the integers in the array is equal to 0.
        - At the end return the array.

    Explanation:-
        Main function:-
            * Creating an array of size n, and initializing all the elements to 0.
            * If n is odd,
                then calling the helper function with
                    left pointer as n/2 - 1 and right pointer as n/2 + 1.
            * If n is even,
                then calling the helper function with
                    left pointer as n/2 - 1 and right pointer as n/2.
            * Returning the array.

        Helper function:-
            * Initializing a variable val to 1.
            * Initializing the values of i and j with left and right pointers respectively.
            * While both i and j are within the bounds of the array,
                - Setting the value of nums[i] to val.
                - Subtracting value from nums[j], i.e storing -ve value of the same as nums[i].
                - Incrementing value by 1.
                - Decrementing i by 1 and incrementing j by 1.
            * Thus convering the entire array with unique integers
                such that the sum of all the integers in the array is equal to 0.
*/
class Solution {
public:
    void conv(vector<int>& nums, int left, int right){
        int val = 1;
        for(int i = left, j = right; i >= 0 && j < nums.size(); i--, j++){
            nums[i] = val;
            nums[j] -= val;
            val++;
        }
    }

    vector<int> sumZero(int n) {
        vector<int> nums(n, 0);

        if(n%2 != 0)
            conv(nums, n/2 - 1, n/2 + 1);
        else
            conv(nums, n/2 - 1, n/2);

        return nums;
    }
};
