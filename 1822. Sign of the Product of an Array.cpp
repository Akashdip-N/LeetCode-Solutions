/*
    https://leetcode.com/problems/sign-of-the-product-of-an-array/
*/
/*
    Solution Approach:-

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of the input array nums

    Intuition:-
        - We have been given an array of integers,
            we have to return the product of the array of numbers.
        - We have to make a function which would follow the following condition:-
            i. If the number is positive, return 1.
            ii. If the number is negative, return -1.
            iii. If the number is zero, return 0.

    Explanation:-
        * Iterating over each element in the array and
            multiplying the product by passing it through the function
                and getting the result from it instead.
        * At the end, returning the product.
*/
class Solution {
public:
    int signFunc(int x){
        if(x > 0) return 1;
        if(x < 0) return -1;
        return 0;
    }

    int arraySign(vector<int>& nums) {
        int product = 1;

        for(int num : nums)
            product *= signFunc(num);

        return product;
    }
};
