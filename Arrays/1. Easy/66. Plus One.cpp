/*
    https://leetcode.com/problems/plus-one/
*/
/*
    Solution Approach:-

    * Checking if the digit is 9 then replacing it with 0
    * If we encounter any digit other than 9 just increment the value and return the array.
    * Outside the loop, if the left-most digit is 0 then add 1 in front of it.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--)
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                ++digits[i];
                return digits;
            }

        if(digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
