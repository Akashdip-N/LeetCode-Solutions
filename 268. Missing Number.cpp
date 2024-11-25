/*
    https://leetcode.com/problems/missing-number/
*/

class Solution {
public: // runtime of this solution is very high
    int missingNumber(vector<int>& nums) {
        std::vector<int>::iterator it;
        for(int i = 0; i < nums.size(); i++){
            it = find(nums.begin(), nums.end(), i);
            if(it == nums.end())
                return i;
        }
        return nums.size();
    }
};
/******************************************************/
class Solution {
public: // 50 ms runtime
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size * (size + 1) / 2;
        for(int& i : nums)
            sum -= i;
        return sum;
    }
};
/*****************************************************/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++)
            if(nums[i] != i)
                return i;
        
        return size;
    }
};