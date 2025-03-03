/*
    https://leetcode.com/problems/palindrome-number/
*/
/*
    Time Complexity: O(log10(n))
    Space Complexity: O(1)

    Solution Approach:-
    * We are first trying to get the length of the number,
        and along with that what's the greatest power of 10 that is less than the number.

    * Running a loop to check if the first and last digits are equal,
        and reducing the number by removing the first and last digits.

    * Reducing the div by 100 in each iteration to remove the first and last digits.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long div = 1;
        while(x >= (div*10))
            div *= 10;

        while(x > 0){
            if ((x / div) != (x % 10))
                return false;

            x = (x % div) / 10; // remove the first and last digits
            div /= 100;
        }

        return true;
    }
};
