/*
    https://leetcode.com/problems/two-sum/
*/
/*
    What we are doing in this solution is,
    we are taking each number at a time and then checking if the remainder exists or not
    in the question it is given that there is one solution only
    that means there should be atleast one solution, hence after finding the combination
    we are returining it.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> map;
        // value, position

        for(int i = 0 ; i < nums.size(); i++){
            int rem = target - nums[i];
            if(map.find(rem) != map.end()){
                ret.push_back(map[rem]);
                ret.push_back(i);
                return ret;
            }
            else
                map[nums[i]] = i;
        }
        return ret;
    }
};
