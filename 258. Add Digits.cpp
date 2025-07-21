/*
    https://leetcode.com/problems/add-digits
*/
/*
    Solution Approach: Using loop

    Time Complexity: O(log n)
    Space Complexity: O(1)
    n = number of digits in num

    Explanation:
        - We will continue to sum the digits of num until it becomes a single digit.
        - In each iteration, we extract the last digit using num % 10 and add it
          to a sum variable.
        - We then remove the last digit by performing integer division by 10.
        - Once num is less than 10, we return it as the result.
*/
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }
        return num;
    }
};

/**************************************************************************/
/*
    Alternative Approach: Using digital root formula

    Time Complexity: O(1)
    Space Complexity: O(1)

    Explanation:
    The digital root can be computed using the formula:
    - If num == 0, return 0
    - Otherwise, return 1 + (num - 1) % 9
*/
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;

        return 1 + (num - 1) % 9;
    }
};
