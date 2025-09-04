/*
    https://leetcode.com/problems/valid-anagram/
*/
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
