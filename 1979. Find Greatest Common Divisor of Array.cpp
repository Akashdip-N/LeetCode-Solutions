/*
    https://leetcode.com/problems/find-greatest-common-divisor-of-array/
*/
/*
    Solution Approach: Brute Force

    Time Complexity: O(n log n)
    Space Complexity: O(1)

    Explanation:
        - Sort the array to find the minimum and maximum elements.
        - Iterate from 1 to the maximum element,
            checking if both the minimum and maximum elements are
                divisible by the current number.
        - Keep track of the greatest common divisor found.
        - Return the greatest common divisor found.
 */
class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int great = 1;

        if(nums[0] == nums[size - 1])
            return nums[0];

        for(int i = 1; i <= nums[size - 1] / 2; i++)
            if((nums[0] % i == 0) && (nums[size - 1] % i == 0))
                if(great < i)
                    great = i;

        return great;
    }
};
