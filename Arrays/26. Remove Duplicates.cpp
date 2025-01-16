/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
/*
    2-pointer solution:

    * Using 2 pointers, one to keep a check on the unique elements and
        the other to iterate through the array.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            int count = 1;
            for(int i = 1; i < nums.size(); i++)
                if(nums[i] != nums[i - 1]){
                    nums[count] = nums[i];
                    count++;
                }

            return count;
        }
};

/****************************************************************************/
/*
    My own solution:

    * Stack to keep a check of the unique elements.
    * Vector to store the unique elements.
    * Copy the vector to the original array.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            stack<int> s;
            vector<int> arr;

            for(auto i : nums)
                if(s.empty() || s.top() != i){
                    s.push(i);
                    arr.push_back(i);
                }

            nums.clear();
            nums = arr;
            return nums.size();
        }
};
