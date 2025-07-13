/*
    https://leetcode.com/problems/group-anagrams/
*/
/*
    Solution Approach:- Using sorting

    Time Complexity: O(N * K log K)
    Space Complexity: O(N * K)

    n = number of strings
    k = maximum length of the string we are considering

    Explanation:
        - Iterating through each string in the input list,
            we sort the characters of the string to create a key.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        for(auto i : mp)
            ans.push_back(i.second);

        return ans;
    }
};

/******************************************************************************/
/*
    Solution Approach:- Using Count Array & Hash Map

    Time Complexity: O(N * K)
    Space Complexity: O(N * K)

    n = number of strings
    k = maximum length of the string we are considering

    Explanation:
        - For each string, we create a key based on the frequency of each character.
        - We use a vector of size 26 to count the occurrences of
            each character (assuming lowercase English letters).
        - The key is formed by concatenating the counts
            of each character, separated by a delimiter.
        - We then use this key to group anagrams together in a hash map.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto str : strs){
            string key = "";
            vector<int> count(26, 0);
            for(char c : str)
                count[c - 'a']++;

            for(int i = 0; i < 26; i++)
                key += to_string(count[i]) + "#";

            mp[key].push_back(str);
        }

        for(auto i : mp)
            ans.push_back(i.second);

        return ans;
    }
};
