/*
    https://leetcode.com/problems/minimum-size-subarray-sum
*/
/*
    Solution Approach: Using Sliding Window Technique

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:
        - We use two pointers, `l` and `r`, to maintain a sliding window.
        - First we store the `max_int` into the `ans` variable,
            so that we can find the minimum length of the subarray.
        - We iterate through the array with the right pointer `r`,
            adding the current element to `sum`.
        - If the `sum` is greater than or equal to the target,
            we decrease the `sum` by the leftmost element and
                move the left pointer `l` one step to the right.
        - We update the `ans` variable with the
            minimum length of the subarray found so far.
        - Finally, we return `ans` if it is not equal to `max_int`,
            otherwise we return 0 indicating no valid subarray was found.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int ans = INT_MAX, l = 0, sum = 0;

        for(int r = 0; r < n; r++){
            sum += nums[r];

            while(sum >= target){
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};
