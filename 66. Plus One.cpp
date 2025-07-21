/*
    https://leetcode.com/problems/plus-one/
*/
/*
    Solution Approach:- Coming from end to the beginning

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the input vector

    Explanation:
        - We iterate from the last digit to the first digit.
        - If the current digit is 9, we set it to 0 and continue to the next digit.
        - If the current digit is not 9, we simply increment it by 1 and return the vector.
        - If we finish the loop and all digits were 9,
            we insert a 1 at the beginning and return the vector.
        - At the end, we return the modified vector.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                ++digits[i];
                return digits;
            }
        }

        // To handle cases where the digits are all 9
        if(digits[0] == 0)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};
