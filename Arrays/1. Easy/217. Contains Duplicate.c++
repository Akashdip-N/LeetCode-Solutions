/*
    https://leetcode.com/problems/contains-duplicate/
*/
/*
    Sorting Solution Approach:-

    To implement this solution:-
    1. Sort the array
    2. Initialize a variable num with the first element of the array
    3. Traverse the array from the second element
        a. If the current element is equal to num,
            then return true
        b. Update num with the current element
    4. Return false
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {          // Space Complexity: O(1)
        sort(nums.begin(), nums.end());                  // O(nlogn)
        int num = nums[0];

        for (int i = 1; i < nums.size(); i++){          // O(n)
            if (num == nums[i])
                return true;
            num = nums[i];
        }

        return false;
    }
};

/*
    Set Solution Approach:-

    To implement this solution:-
    1. Initialize an unordered_set<int> s
    2. Traverse the array
        a. If the element is already present in the set,
            then return true
        b. Else, add the element to the set
    3. Return false
*/
class Solution {                                        // Space Complexity: O(n)
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (auto num : nums){                          // O(n)
            if (s.find(num) != s.end())                 // O(1)
                return true;
            s.insert(num);
        }

        return false;
    }
};
