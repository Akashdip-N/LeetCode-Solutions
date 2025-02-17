/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
/*

    Solution Approach:-

    1. We will use a sliding window approach.
    2. We will use a set to store the characters.
    3. We will keep track of the left and right pointers.
    4. If the character is already present in the set,
        we will remove the character from the set and increment the left pointer.
    5. We will keep track of the maximum length of the substring.
    6. We will return the maximum length of the substring.
*/
/*                SLIDING WINDOW APPROACH                        */
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

/*                       HASH MAP APPROACH                          */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;

        int i = 0, j = 0, ans = 0;
        unordered_map<char, int> mp;

        for(int j = 0; j < n; j++){
            if(mp.find(s[j]) != mp.end())
                i = max(i, mp[s[j]]);

            ans = max(ans, j - i + 1);
            mp[s[j]] = j + 1;
        }

        return ans;
    }
};
