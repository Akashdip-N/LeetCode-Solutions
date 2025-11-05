/*
    https://leetcode.com/problems/longest-consecutive-sequence
*/
/*
    Solution Approach:- Using HashSet, and finding the start of each sequence.

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of input array

    Explanation:
        * Creating a hashset with all elements from the input array.
        * Iterating through each number in the hashset.
        * Checking if the number is the start of a sequence
            (i.e., num - 1 is not in the set).
        * If it is the start, we count the length of the sequence
            by checking for consecutive numbers (num + 1, num + 2, ...).
        * Updating the longest streak found so far.
        * Finally, returning the length of the longest consecutive sequence.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
