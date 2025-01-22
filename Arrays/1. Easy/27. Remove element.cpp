/*
    https://leetcode.com/problems/remove-element/
*/
/*
    * Two pointers approach.
    * One pointer to iterate the array
    * Another pointer to place the elements which are not equal to val.

    * Time complexity: O(n)
    * Space complexity: O(1)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            if(nums[i] != val)
                nums[count++] = nums[i];

        return count;
    }
};
