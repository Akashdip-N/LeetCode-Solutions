/*
    https://leetcode.com/problems/single-number/
*/
/*
    Solution Approach:- Using Bit Manipulation (XOR)

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input array

    Intuition:-
        - Given us a array of integers, where every element appears twice except for one.
        - We have to find that single element which appears only once.
        - CONSTRAINTS ARE:-
            * The algorithm should have a linear runtime complexity.
            * We should implement it without using extra memory.

        - We would use XOR operation to find the single number.
        - The properties of XOR operation are:
            1. a ^ a = 0 (XOR of a number with itself is 0)
            2. a ^ 0 = a (XOR of a number with 0 is the number itself)
            3. XOR is commutative and associative,
                which means the order of operations does not matter.
        - So, if we XOR all the numbers in the array,
            the numbers that appear twice will cancel each other out and
                we will be left with the single number.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums){
        int res = 0;

        for(int num : nums)
            res ^= num;

        return res;
    }
};

/**************************************************************************************************/
/*
    Solution Approach:- Using STL (Standard Template Library)

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input array

    Intuition:-
        - Same as above, but instead using STL functions to make the code more concise and readable.

    Explanation:-
        - We can use the `accumulate` function from the `<numeric>` header in C++,
            which allows us to accumulate values in a range.
            (
                more info:-
                https://www.geeksforgeeks.org/cpp/accumulate-and-partial_sum-in-c-stl-numeric-header/
            )
        - We can use the `bit_xor` function from the `<functional>` header,
            which allows us to perform bitwise XOR operation.
            (
                more info:-
                https://www.geeksforgeeks.org/cpp/stdbit_xor-in-c-with-examples/
            )
        - By using `accumulate` with `bit_xor`, we can find the single number in the array
            without using extra memory and in linear time complexity.
*/
class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};
