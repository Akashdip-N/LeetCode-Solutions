/*
    https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> a;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        size_t size = nums.size();
        for (int i = 0; i < size - 2; i++){
            int low = i + 1, high = size - 1;
            while (low < high)
                if((nums[i] + nums[low] + nums[high]) < 0)
                    low++;
                else if ((nums[i] + nums[low] + nums[high]) > 0)
                    high--;
                else{
                    s.insert({nums[i], nums[low], nums[high]});
                    low;
                    high--;
                }
        }
        for(auto it : s)
            a.push_back(it);

        return a;
    }
};