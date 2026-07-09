/*
    https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
*/
/*
    Solution Approach:- Digit Extraction and Calculation

    Time Complexity: O(logN)
    Space Complexity: O(1)
    N = size of the input number

    Explanation:
        * We extract each digit from the number n using modulo and division.
        * We filter out the non-zero digits,
            calculating their sum and constructing a new number from them.
        * Finally, we return the product of the filtered number and the sum of its digits.
 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long filtered_num = 0;
        long long sum = 0;
        long long multiplier = 1;

        while (n > 0) {
            int dig = n % 10;

            if (dig != 0) {
                sum += dig;
                filtered_num += dig * multiplier;
                multiplier *= 10;
            }

            n /= 10;
        }

        return filtered_num * sum;
    }
};

/**************************************** OWN SOLUTION ****************************************/
/*
    Solution Approach:- Using Stack

    Time Complexity: O(logN)
    Space Complexity: O(logN)
    N = size of the input number

    Explanation:
        * We extract each digit from the number n using modulo and division.
        * We filter out the non-zero digits,
            calculating their sum and pushing them onto a stack to maintain order.
        * Finally, we pop from the stack to construct the new number
        * Return the product of this number and the sum of its digits.
 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        long long ret = 0;
        stack<int> s;
        int power = 0;

        while(n > 0){
            int dig = (n)%10;

            if(dig != 0) {
                sum += dig;
                s.push(dig * pow(10, power));
                power++;
            }

            n /= 10;
        }

        while(!s.empty()){
            int val = s.top();
            ret += val;
            s.pop();
        }

        return ret*sum;
    }
};
