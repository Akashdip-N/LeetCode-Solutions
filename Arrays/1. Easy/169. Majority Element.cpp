/*
    https://leetcode.com/problems/majority-element/
*/
/*
    Boyer-Moore Voting Algorithm Solution Approach:-

    To implement this solution,
    1. Initialize ans = nums[0] and freq = 0
    2. Traverse the array
        a. If freq == 0, which means the frequency of the current element is 0,
            then update ans = nums[i]
        b. If ans == nums[i], which means the current element is the majority element,
            then increment freq
        c. Else, decrement freq
    3. Return ans
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], freq = 0;
        for (int i = 0; i < nums.size(); i++){
            if (freq == 0)
                ans = nums[i];

            if (ans == nums[i])
                freq++;
            else
                freq--;
        }

        return ans;
    }
};

/*************************************************************************/

/*
    Map Implementation Solution Approach:-

    To implement this solution:-
    1. Initialize an unordered_map<int, int> mp
    2. Traverse the array
        a. If the element is not present in the map,
            then add the element to the map with value 1
        b. Else, increment the value of the element in the map
        c. If the value of the element in the map is greater than n/2,
            where n is the size of the array, then return the element
    3. Return 0
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        if(nums.size() == 1)
            return nums[0];

        for(auto num : nums)
            if(mp.find(num) == mp.end())
                mp[num] = 1;
            else{
                mp[num]++;
                if(mp[num] > nums.size()/2)
                    return num;
            }

        return 0;
    }
};
