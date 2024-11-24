/*
    https://leetcode.com/problems/search-insert-position/
*/
// this is the better solution than the below one
// both the codes are done by me :)
class Solution { 
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = 0;
        if(nums[nums.size()-1] < target)
            return nums.size();
        else
            if(target < nums[0])
                return 0;
        else
        {
            int size = nums.size();
            int half = (nums.size() / 2);
            while (nums[half] != target){
                if(nums[half] < target)
                    half = (size + half)/2;
                else if(nums[half] > target)
                    half = (0 + half)/2;
            }

            for(int i = 0; i < (nums.size()-1); i++)
                if((nums[i] < target) && (target < nums[i+1]) )
                    return (i + 1);
        }
        return 1;
    }
};

/*---------------------------------------------------------------*/
class Solution { 
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = 0;
        if(nums[nums.size()-1] < target)
            return nums.size();
        else
            if(target < nums[0])
                return 0;
        else
        {
            for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target)
                return i;
        
            for(int i = 0; i < (nums.size()-1); i++)
                if((nums[i] < target) && (target < nums[i+1]) )
                    return (i + 1);
        }
        return 1;
    }
};

/*---------------------------------------------------------------*/
// This is done using binary search algorithm
class Solution { 
public:
    int searchInsert(vector<int>& nums, int target) {
        
    }
};