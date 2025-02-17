/*
    https://leetcode.com/problems/first-unique-character-in-a-string/
*/
/*
    Solution Approach:
    * We are using a hash map to store the frequency of each character in the string.
    * Then we are iterating over the string and
        checking if the frequency of the character is 1.
    * If it is 1, we are returning the index of the character.
    * If no character has a frequency of 1, we are returning -1.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        unordered_map<char, int> mp;

        for(int i = 0; i < size; i++)
            mp[s[i]]++;

        for(int i = 0; i < size; i++)
            if(mp[s[i]] == 1)
                return i;

        return -1;
    }
};
