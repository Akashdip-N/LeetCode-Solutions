/*
    https://leetcode.com/problems/split-array-with-minimum-difference
*/
/*
    Solution Approach:- Using Prefix Sum and Two Pointers

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of input array

    Explanation:-
        * Checking till which index the array is increasing
            And till which index it is decreasing,
                this is done by checking
                    if the previous element holds the same property
                        and the current element is greater/lesser than the previous one.
        * But for the decreasing array, we check from the end of the array.
        * Then we calculate the prefix sum of the array for that
            specific index.
        * Then we check for the indices where the array is increasing
            and the next index is decreasing.
        * Then we calculate the left and right sum of the array
            and calculate the absolute difference.
        * We keep track of the minimum absolute difference
            and return it at the end.
        * If no such index is found, we return -1.
*/
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return -1;

        vector<char> inc(size, 0), dec(size, 0);
        inc[0] = 1;
        for (int i = 1; i < size; ++i)
            inc[i] = inc[i-1] && (nums[i-1] < nums[i]);

        dec[size-1] = 1;
        for (int i = size - 2; i >= 0; --i)
            dec[i] = dec[i+1] && (nums[i] > nums[i+1]);

        vector<long long> pref(size);
        pref[0] = nums[0];
        for (int i = 1; i < size; ++i)
            pref[i] = pref[i-1] + nums[i];

        long long total = pref[size-1];
        long long ret = -1;

        for (int i = 0; i < size - 1; ++i) {
            if (inc[i] && dec[i+1]) {
                long long left  = pref[i];
                long long right = total - left;
                long long diff  = abs(left - right);

                if (ret == -1 || diff < ret)
                    ret = diff;
            }
        }
        return ret;
    }
};
