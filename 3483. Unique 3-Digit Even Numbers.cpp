/*
    https://leetcode.com/problems/unique-3-digit-even-numbers
*/
/*
    Solution Approach: Using set to store the unique 3-digit even numbers.

    Time Complexity: O(n^3), n = size of digits array.
    Space Complexity: O(n), for storing unique numbers.

    Explanation:-
        i. Iterate through each value of the digits array.
        ii. Using three nested loops, generate all possible 3-digit combinations.
        iii. If the first value is a zero, skip that value and go to the next value.
        iv. In the second and third loop,
                skip if the digits are same.
        v. In the innermost loop, check if the last digit is even,
                if yes, then form the number and insert it into the set.
        vi. At last, return the size of the set
            which contains unique 3-digit even numbers.
*/
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;

        for (int i = 0; i < digits.size(); ++i) {

            // Skip leading zero
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < digits.size(); ++j) {

                // Skip if the same digit is used for both i and j
                if (i == j)
                    continue;

                for (int k = 0; k < digits.size(); ++k) {

                    // Skip if the same digit is used for i, j, or k
                    if (i == k || j == k)
                        continue;

                    // Check if the last digit is even
                    if (digits[k] % 2 == 0) {
                        int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                        uniqueNumbers.insert(number);
                    }
                }
            }
        }

        return uniqueNumbers.size();
    }
};
