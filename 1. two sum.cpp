/*
    https://leetcode.com/problems/two-sum/
*/
/*
    Solution Approach:- Using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = size of the input array

    Explanation:-
        i. Create an unordered map to store the elements and their indices.
        ii. Iterate through the array and for each element, calculate the
            complement (target - current element).
        iii. Check if the complement exists in the map.
            a. If it does, return the indices of the current element and the complement.
            b. If it doesn't, add the current element and its index to the map.
        iv. If no such pair is found, return an empty vector.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> map;

        for(int i = 0 ; i < nums.size(); i++){
            int rem = target - nums[i];

            if(map.find(rem) != map.end())
                return {map[rem], i};
            else
                map[nums[i]] = i;
        }

        return ret;
    }
};
