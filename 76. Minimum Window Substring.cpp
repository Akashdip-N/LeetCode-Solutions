/*
    https://leetcode.com/problems/minimum-window-substring
*/
/*
    Solution Approach: Sliding Window + Hash Map

    Time Complexity: O(N + M)
    Space Complexity: O(M)
    N = length of string s
    M = length of string t

    Explanation:
        i. First store the frequency of characters in string t in a hash map.
        ii. Using two pointers, left and right, we will traverse the string s.
        iii. We will keep expanding the right pointer until
            we have a valid window that contains all characters of t.
        iv. Once we have a valid window,
            we will try to shrink the window by moving the left pointer to the right,
                while still maintaining a valid window.
        v. We will keep track of the minimum length of the valid window and its starting index.
        vi. Finally, we will return the substring of s starting from the starting index
            with the minimum length.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";

        unordered_map<char, int> freq;
        for(char c : t)
            freq[c]++;

        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while(right < s.size()){
            // If the character is present in t, decrease the count
            if(freq[s[right]] > 0)
                count--;

            // Decrease the frequency of the character
            freq[s[right]]--;
            right++;

            // When we have a valid window
            while(count == 0){
                // Update the minimum length and start index
                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }

                // Increase the frequency of the character at left pointer
                freq[s[left]]++;

                // If the character is present in t, increase the count
                if(freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
