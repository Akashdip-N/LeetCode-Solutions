/*
    https://leetcode.com/problems/partition-labels
*/
/*
    Solution Approach: Using Hash Map, Two Pointers

    Time Complexity: O(n)
    Space Complexity: O(1) (atmost 26 characters in the alphabet)
    n = length of the string s

    Explanation:
        - Storing the last index of each character in a hash map.
        - Using two pointers,
            one for the start of the partition and
                another to track the end of the current partition.
        - If the current index reaches the end of the partition,
            we push the size of the partition into the result vector.
        - The process continues until we traverse the entire string.
        - Return the result vector containing the sizes of the partitions.
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int size = s.size();
        unordered_map<char, int> lastIndex;

        for(int i = 0; i < size; ++i)
            lastIndex[s[i]] = i;

        vector<int> ret;
        int start = 0, end = 0;

        for(int i = 0; i < size; ++i) {
            end = max(end, lastIndex[s[i]]);

            if(i == end) {
                ret.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ret;
    }
};
