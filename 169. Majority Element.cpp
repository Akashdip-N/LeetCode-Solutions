/*
    https://leetcode.com/problems/majority-element/
*/
/*
    Solution Approach: Boyer-Moore Voting Algorithm

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the array

    Explanation:
        - We maintain a candidate for the majority element and a frequency counter.
        - If the frequency counter is zero, we set the current element as the candidate.
        - If the current element matches the candidate, we increment the frequency counter.
        - If it does not match, we decrement the frequency counter.
        - At the end of the traversal, the candidate will be the majority element.
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
    Solution Approach: Using Sorting

    Time Complexity: O(n log n)
    Space Complexity: O(1)
    n = size of the array

    Explanation:
        - We sort the array and return the middle element.
        - The middle element will always be the majority element
            since it appears more than n/2 times.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/*************************************************************************/
/*
    Solution Approach: Using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = size of the array

    Explanation:
        - Hash map to count and store the frequency of each element.
        - For each element, we check if its frequency exceeds n/2.
            Then we return the element as the majority element.
        - If the array has only one element, we return that element.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        if(nums.size() == 1) return nums[0];

        for(auto num : nums) {
            if(mp.find(num) == mp.end())
                mp[num] = 1;
            else{
                mp[num]++;

                if(mp[num] > nums.size()/2)
                    return num;
            }
        }

        return 0;
    }
};
