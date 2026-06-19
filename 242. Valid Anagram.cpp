/*
    https://leetcode.com/problems/valid-anagram/
*/
/*
    Solution Approach:- Using Hash-Map

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = length of the first string (s)

    Explanation:-
        - Storing the frequency of each character in the first and second
            strings in two separate hash maps.
        - Iterating through one of the strings and
            checking if the frequency of each character in both hash maps is the same.
        - If the frequency of any character is different, returning false.
        - If all characters have the same frequency, returning true.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(auto c : s) m1[c]++;
        for(auto ch : t) m2[ch]++;

        for(auto c : s)
            if(m1[c] != m2[c]) return false;

        return true;
    }
};

/***********************************************************************************/
/*
    Solution Approach:- Using Hash Map

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = length of the first string (s)

    Explanation:
        - Storing all the characters of the first string in a hash map.
        - Iterating through each character of the second string,
            and checking if it is present in the hash map.
        - If present, decrementing its count in the hash map.
        - If the count becomes zero, removing the character from the hash map.
        - Finally, if the hash map is empty, returning true, else false.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        for(auto i : s)
            mp[i]++;

        for(auto i : t) {
            if(mp.find(i) == mp.end())
                return false;

            mp[i]--;
            if(mp[i] == 0)
                mp.erase(i);
        }

        return true;
    }
};

/***********************************************************************************/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(N log N)
    Space Complexity: O(1)
    N = length of the first string (s)

    Explanation:
        - Base case, if the size of the strings are not equal.
        - Sorting both the strings.
        - Compare the two sorted strings, and return the result.
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
