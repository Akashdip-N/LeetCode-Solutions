/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
/*
    Solution Approach: Two Pointers
    Time Complexity: O(n), n = size of the input array
    Space Complexity: O(1), in-place modification of the input array

    Explanation:
        i. Store the position of the first element from the sorted array in `pos`.
        ii. Create a variable `count` to keep track of the number of unique elements.
        iii. Iterate through the array starting from the second element,
                and check if the current element is different from the element at `pos`,
                    if true then swap the current element with the element at `pos`,
                        and increment the `count` of unique elements.
        iv. Return the count of unique elements.
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
