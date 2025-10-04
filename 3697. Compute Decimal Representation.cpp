/*
    https://leetcode.com/problems/compute-decimal-representation
*/
/*
    Solution Approach:- Digit-by-Digit Iterative Solution

    Time Complexity:- O(log(N))
    Space Complexity:- O(log(N))
    N = size of the input number

    Explanation:-
        * Initialize a vector to store the decimal representation.
        * Initialize a variable to keep track of the power of 10.
        * Iterate through the digits of the input number.
        * If the current digit is not zero, multiply it by the power of 10 and add it to the vector.
        * Update the power of 10 and divide the input number by 10.
        * Reverse the vector to get the correct order.
        * Return the vector.
*/
class Solution {
public:
    vector<int> decimalRepresentation(long int n) {
        vector<int> ret;
        long int pow = 1;

        while(n > 0){
            long int num = n % 10;
            if (num != 0)
                ret.push_back(num*pow);

            pow *= 10;
            n /= 10;
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};
