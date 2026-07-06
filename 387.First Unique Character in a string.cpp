/*
    https://leetcode.com/problems/first-unique-character-in-a-string/
*/
/*
    Solution Approach: HashMap (Using vector as HashMap)

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the string

    Explanation:-
        * Since vectors have fixed position, where the elements are stored in the memory.
        * The lookup time to find the frequency of a character is faster than unordered_map.
*/
class Solution {
public:
    long long firstUniqChar(string s) {
        vector<int> mp(27,0);
        for(char c:s)
            mp[c-'a']++;

        for(int i=0;i<s.length();i++)
            if(mp[s[i]-'a']==1)
                return i;

        return -1;
    }
};

/*************************************************************************************************/
/*
    Solution Approach: HashMap

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the string

    Explanation:-
        * Using HashMap to store the frequency of each character in the string.
        * Iterating over each character of the string,
            and if the frequency of the character is 1,
                return the index of that character.
        * If no unique character is found, return -1.
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
