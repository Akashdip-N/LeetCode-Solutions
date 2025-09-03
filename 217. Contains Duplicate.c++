/*
    https://leetcode.com/problems/contains-duplicate/
*/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(nlogn)
    Space Complexity: O(1)

    Explanation:-
        i. Sort the array
        ii. Traverse the array and
            check if the current element is equal to the previous element.
        iii. If yes, return true.
        iv. If no, continue traversing the array.
        v. If no duplicates are found, return false.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = nums[0];

        for (int i = 1; i < nums.size(); i++){
            if (num == nums[i])
                return true;
            num = nums[i];
        }

        return false;
    }
};
/************************************************************************************/
/*
    Solution Approach:- Using Hashmap

    Time Complexity: O(n)
    Space Complexity: O(n)

    Explanation:-
        i. Create an unordered map to store the elements of the array.
        ii. Traverse the array and
            check if the current element is already present in the map.
        iii. If yes, return true.
        iv. If no, insert the element in the map.
        v. If no duplicates are found, return false.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool>m;

        for(int num : nums){
            if(m[num])
                return true;
            m[num] = true;
        }

        return false;
    }
};
