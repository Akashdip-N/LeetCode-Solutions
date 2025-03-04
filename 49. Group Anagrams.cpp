/*
    https://leetcode.com/problems/group-anagrams/
*/
/*
    Solution Approach:-

    * Sorting the string and using it as a key in the map.
    * Iterate through the map and push the values into the answer vector.
    * Return the answer vector.
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
