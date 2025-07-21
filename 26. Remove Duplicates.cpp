/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
/*
    Solution Approach: Two Pointers Approach

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the input array

    Explanation:
        i. Bringing all the unique elements to the front of the array.
        ii. Using `pos` to track the position of the last unique element.
        iii. Incrementing `count` for each unique element found.
        iv. The final count of unique elements is returned.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        int count = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[pos]) {
                pos++;
                nums[pos] = nums[i];
                count++;
            }
        }

        return count;
    }
};
