/*
    https://leetcode.com/problems/contains-duplicate-ii/
*/
/*
    Solution Approach:- Using HashMap

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = size of the input array

    Intuition:-
        - Given us an array of integers and an integer k.
        - We need to check if there exists the following condition then return true:-
            i. Value of nums[i] == nums[j]
            ii. Absolute value of (i - j) <= k
        - Else return false.

        - Using HashMap to fetch the number and its index.

    Explanation:-
        * Creating a HashMap to store the number and its index.
        * Iterating through index 0 till the end of the array.
        * For each index we perform the following operations:-
            - Check if the number is already present in the HashMap.
            - If it is present then we check if the absolute value of (i - j) <= k.
            - If it is true then we return true.
            - Else we update the index of the number in the HashMap.
        * At the end if we don't find any such pair then we return false.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end())
                if(i - m[nums[i]] <= k)
                    return true;

            m[nums[i]] = i;
        }

       return false;
    }
};

/****************************************************************************************/
/*
    Solution Approach:- Using Sliding Window and HashSet

    Time Complexity:- O(N)
    Space Complexity:- O(min(N, K))
    N = size of the input array
    K = size of the sliding window

    Intuition:-
        - Same as the previous approach.
        - Instead of using HashMap we use HashSet to store the numbers in the current window.

    Explanation:-
        * Creating a HashSet to store the numbers in the current sliding window.
        * Iterating through index 0 till the end of the array.
        * For each index we perform the following operations:-
            - If the size of the sliding window is greater than k
                then we remove the leftmost element from the HashSet.
                    and increment the left pointer.
            - Check if the number is already present in the HashSet,
                that means it's a valid pair and we return true.
            - Else we add the number to the HashSet.
        * At the end if we don't find any such pair then we return false.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0;
        unordered_set<int> s;

        for(int right = 0; right < size; right++){
            if(right - left > k){
                s.erase(nums[left]);
                left++;
            }

            if(s.find(nums[right]) != s.end())
                return true;

            s.insert(nums[right]);
        }

        return false;
    }
};
