/*
    https://leetcode.com/problems/sqrtx/
*/
/*
    Solution Approach:- Using Binary Search
    Time Complexity:- O(log(n))
    Space Complexity:- O(1)

    Explanation:-
        Since, we can't use any inbuilt function to find the square root of a number,
            we will search the number from 1 till x/2.

        Steps:-
        1. Assinging left = 1 and right = x/2
        2. while the left side is less than the right side.
        3. Calculating the mid value, to check
            if the square of mid is equal to x or not,
                then we will return mid,
            else,
                if the square of the mid is less than the number,
                    which means the square of the next number will be greater than the number,
                        (
                            hence, we store the mid value in ans,
                                we are storing the number because we have to return
                                    an integer value of the square root
                        )
                        and move the left side to mid + 1.
            else,
                we will store mid - 1 in the right side,
                    thus reducing the search space.
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == x)
                return mid;
            else
                if (square < x) {
                    // when the sqrt value is not a integer.
                    ans = mid;
                    left = mid + 1;
                }
            else
                right = mid - 1;
        }

        return ans;
    }
};
