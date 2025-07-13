/*
    https://leetcode.com/problems/valid-anagram/
*/
/*
    Solution Approach:- Using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)

    Explanation:
        - First storing all the characters of string s
            in a hash map with their counts.
        - Iterating through each character in string t:
            - If the character exists in the map, we decrement its count.
            - If the count reaches zero, we remove that character from the map,
                because the number of occurrences of that character in t matches with s.
            - If we find any character in t that does not exist in the map,
                we return false.
        - After the loop gets completed, we return true,
            indicating that both strings are anagrams of each other.
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

/**************************************************************************/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(n log n)
    Space Complexity: O(1)

    Explanation:
        - First we sort both strings s and t.
        - If the sorted strings are equal, then they are anagrams of each other.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
