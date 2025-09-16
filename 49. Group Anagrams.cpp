/*
    https://leetcode.com/problems/group-anagrams/
*/
/*
    Solution Approach:- Using Count Array

    Time Complexity: O(N * k)
    Space Complexity: O(N * k)

    N = number of strings in the input list
    k = lenght of the string we are currently working

    Explanation:
        - For each string, we create a key based on the frequency of each character.
        - We use a vector of size 26 to count the occurrences of
            each character in the string, since the characters are in lowercase.
        - The key is formed by concatenating the counts
            of each character, separated by a delimiter.
        - We then use this key to group anagrams together in a hash map.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto str : strs) {
            string key = "";

            vector<int> count(26, 0);
            for(char c : str)
                count[c - 'a']++;

            for(int i = 0; i < 26; i++)
                key += to_string(count[i]) + "#";

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto i : mp)
            ans.push_back(i.second);

        return ans;
    }
};

/**************************************************************************************/
/*
    Solution Approach:- Using sorting

    Time Complexity: O(N * k log k)
    Space Complexity: O(N * k)

    N = number of strings in the input list
    k = lenght of the string we are currently working

    Explanation:
        - For each string in the input list, we sort the string to create a key.
        - Storing the string based on the sorted key in a hash map.
        - Pushing the map second value,
            i.e. the vector of strings to the answer vector.
        - Finally returning the answer vector.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto i : mp)
            ans.push_back(i.second);

        return ans;
    }
};
