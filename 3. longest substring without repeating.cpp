/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
/************************ SLIDING WINDOW APPROACH ************************* */
/*
    Solution Approach:- Sliding Window Approach

    * Using set to store the unique characters.
    * Using for loop to iterate over the string.
    * Using a while loop to check for repeating characters
        in the set and incrementing the left pointer
            and removing the left character from the set.
    * Storing the unique characters in the set.
    * Calculating the max length of the substring.
    * Returning the max length.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0)
            return 0;

        int ans = 1, l = 0;
        set<char> st;

        for(int r = 0; r < size; r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

/************************ HASH MAP APPROACH ************************* */
/*
    Solution Approach:- Using Hash Map

    * Using a hash-map to store the character and its index.
    * Using a loop to iterate over the string.
    * Checking if the character is already present in the hash-map.
        If yes, updating the left pointer to the max of th
            current left pointer and the index of the character.
    * Storing the unique characters in the hash-map.
    * Calculating the max length of the substring.
    * Returning the max length.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;

        int i = 0, ans = 0;

        // <character, index>
        unordered_map<char, int> mp;

        // abcabc
        // 012345

        for(int j = 0; j < n; j++){
            if(mp.find(s[j]) != mp.end())
                i = max(i, mp[s[j]]);

            ans = max(ans, j - i + 1);
            mp[s[j]] = j + 1;
        }

        return ans;
    }
};
