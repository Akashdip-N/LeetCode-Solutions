/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
/*
    Solution Approach:- Using Sliding Window

    Time Complexity: O(n)
    Space Complexity: O(min(m, n))

    n = length of the string
    m = length of the palindrome string

    Explanation:
        - Using set to store unique characters.
        - Using two pointers, left and right, to maintain the window.
        - If the character at the right pointer is already in the set,
            we remove characters from the left pointer until it is not in the set.
        - We then insert the character at the right pointer into the set.
        - We calculate the maximum length of the substring without repeating characters.
        - Finally, we return the maximum length.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        int ans = 1, l = 0;
        unordered_set<char> st;

        for(int r = 0; r < n; r++){
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

/******************************************************************************/
/*
    Solution Approach:- Using Hash Map with Sliding Window

    Time Complexity: O(n)
    Space Complexity: O(min(m, n))

    n = length of the string
    m = length of the palindrome string

    Explanation:
        - Using a hash map to store the last index of each character.
        - Using two pointers, left and right, to maintain the window.
        - If the character at the right pointer is already in the hash map,
            we update the left pointer to the maximum of
                its current value and the index of the character in the hash map.
        - We calculate the maximum length of the substring without repeating characters.
        - We store the index of the character in the hash map.
        - Finally, we return the maximum length.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;

        int l = 0, ans = 0;
        unordered_map<char, int> mp;

        for(int r = 0; r < n; r++){
            if(mp.find(s[r]) != mp.end())
                l = max(l, mp[s[r]]);

            ans = max(ans, r - l + 1);
            mp[s[r]] = r + 1;
        }

        return ans;
    }
};
