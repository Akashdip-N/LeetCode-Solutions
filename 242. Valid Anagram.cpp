/*
    https://leetcode.com/problems/valid-anagram/
*/
/*
    Solution Approach:
    * We are using a hash map to store the frequency of each character in the string s.
    * Then we are iterating over the string t and
        checking if the character is present in the hash map.
    * If it is present, we are decrementing the frequency of the character.
    * If the frequency of the character becomes 0,
        we are removing the character from the hash map,
            which means that the character is present in both the strings.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        for(auto i : s)
            mp[i]++;

        for(auto i : t){
            if(mp.find(i) == mp.end())
                return false;
            mp[i]--;
            if(mp[i] == 0)
                mp.erase(i);
        }

        return true;
    }
};
