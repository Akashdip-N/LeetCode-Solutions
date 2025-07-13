/*
    https://leetcode.com/problems/move-zeroes/
*/
/*
    Solution Approach: Using Two Pointers

    Time Complexity: O(n)
    Space Complexity: O(1)

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
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0){
                swap(nums[l], nums[i]);
                l++;
            }
    }
};
