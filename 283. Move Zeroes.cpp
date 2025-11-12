/*
    https://leetcode.com/problems/move-zeroes/
*/
/*
    Solution Approach: Using Two Pointers / In-Place Swapping

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input array

    Explanation:
        - Iterate through the entire array.
        - When a non-zero element is found,
            swap it with the element at the left pointer.
        - Increment the left pointer.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[l], nums[i]);
                l++;
            }
        }
    }
};
