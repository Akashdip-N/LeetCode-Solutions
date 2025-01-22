/*
    https://leetcode.com/problems/move-zeroes/
*/
/*
    Two Pointer Solution Approach:-

    To implement this solution:-

    1. Initalize the left pointer to 0
    2. Traverse the array
        a. If the current element is not equal to 0,
            then swap the current element with the element at the left pointer
            and increment the left pointer

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
