/*
    https://leetcode.com/problems/contains-duplicate/
*/
/*
    Solution Approach:- Using Hashset

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the input array

    Explanation:-
        i. Create an unordered set to store the elements of the array.
        ii. Traverse the array and
            check if the current element is already present in the set.
        iii. If yes, return true.
        iv. If no, insert the element in the set.
        v. If no duplicates are found, return false.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return false;

        unordered_set<int>m;

        for(int num : nums){
            if(m.find(num) != m.end())
                return true;

            m.insert(num);
        }

        return false;
    }
};

/************************************************************************************/
/*
    Solution Approach:- Using Hashmap

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the input array

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
        int size = nums.size();
        if(size < 2) return false;

        unordered_map<int, bool>m;

        for(int num : nums){
            if(m[num])
                return true;
            m[num] = true;
        }

        return false;
    }
};

/************************************************************************************/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(NlogN)
    Space Complexity: O(1)
    N = size of the input array

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
        sort(nums.begin(), nums.end()); // NlogN time
        int num = nums[0];

        for (int i = 1; i < nums.size(); i++){
            if (num == nums[i])
                return true;
            num = nums[i];
        }

        return false;
    }
};
