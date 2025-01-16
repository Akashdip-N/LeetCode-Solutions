/*
    https://leetcode.com/problems/single-number/
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < (n-1); i++)
            nums[i+1] = nums[i]^nums[i+1];
        return nums[n - 1];
    }
};

/*-------------- 3ms solution -----------------------*/
class Solution {
public:
    int singleNumber(vector<int>& nums){
        int res = 0;
        for(int n : nums)
            res ^= n;
        return res;
    }
};