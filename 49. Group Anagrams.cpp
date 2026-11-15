/*
    https://leetcode.com/problems/group-anagrams/
*/
/*
    Solution Approach:- Using Count Array

    Time Complexity: O(N * K)
    Space Complexity: O(N * K)

    N = number of strings in the input list
    K = lenght of the string we are currently working

    Problem Statement:-
        - We have been given a list of strings and we have to group the anagrams together.
        - Anagrams are words that have the same characters but in different order.
        Ex:-
            - "eat" and "tea" are anagrams of each other.
            - "tan" and "nat" are anagrams of each other.
            - "bat" is not an anagram of any other string in the list.

            vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
            Output:-              [["bat"],["tan","nat"],["eat","tea","ate"]]

    Intuition:-
        - Using a count array of fixed size 26 to count the frequency of each character in the string.
        - By using this concept we can create a unique key for each group of anagrams,
            using `#` as a separator between the counts of each character.
        - And storing the strings based on the key in a hash map.

    Explanation:
        * Creating a hashmap to store the string as a key and the vector of strings as a value.
        * Iterating through the string list, and perfomring the following operation for each string:-
            - Creating the count array of size 26 and initializing it with 0.
            - For each character in the string,
                - First converting the characters into an ASCII value
                    by substracting the ASCII value of 'a' from the character.
                - Then incrementing the count of that character in the count array.
            - Creating a key by iterating through the count array and appending the
                count of each character to the key string with `#` as a separator.
            - Storing the string in the hashmap based on the key.
            Ex:-
                string:-["eat","tea","taaan","ate","naaat","bat"]

                The hashmap will look like this after processing all the strings:-
                {
                    "1#0#0#0#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0#": ["eat", "tea", "ate"],
                    "3#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#1#0#0#0#0#0#0#": ["taaan", "naaat"],
                    "1#1#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#0#1#0#0#0#0#0#0#": ["bat"]
                }

        * Finally, iterating through the hashmap and pushing the vector of strings to the answer vector.
        * Returning the answer vector.
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

            // Running for 26 times only each time, hence O(1) time complexity
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

/******************************************************************************************************/
/*
    Solution Approach:- Using sorting

    Time Complexity: O(N * K log K)
    Space Complexity: O(N * K)

    N = number of strings in the input list
    K = lenght of the string we are currently working

    Intuition:-
        - Using string sorting technique to create a unique key for each group of anagrams.
        - For each string in the input list, we sort the string to create a key.
        - Storing the string based on the sorted key in a hash map.
        Ex:-
            string:-["eat","tea","taaan","ate","naaat","bat"]

            The hashmap will look like this after processing all the strings:-
            {
                "aet": ["eat", "tea", "ate"],
                "aaant": ["taaan", "naaat"],
                "abt": ["bat"]
            }

    Explanation:
        * Creating a hashmap to store the string as a key and the vector of strings as a value.
        * Iterating through the string list, and perfomring the following operation for each string:-
            - Sorting the string to create a key.
            - Storing the string in the hashmap based on the sorted key.
        * Finally, iterating through the hashmap and pushing the vector of strings to the answer vector.
        * Returning the answer vector.
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
