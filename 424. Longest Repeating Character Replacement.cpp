/*
    https://leetcode.com/problems/longest-repeating-character-replacement/
*/
/*
    Solution Approach: Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1) (Because the unordered_map will have at most 26 characters for uppercase English letters)
    N = length of the input string s

    Explanation:
        i. Using left and right pointer pointing at the starting position of the string s i.e. 0
        ii. Using unordered_map to store the frequency of each character in the current window.
        iii. Using loop to iterate through each character in the string s,
            and for each character, first we update the frequency of the character in the unordered_map.
        iv. Then we calculate whether the frequency of the current character is
            greater than the max frequency of any character in the current window.
        v. Storing the size of the current window of strings to work with.
        vi. Storing the number of replacements needed to make all characters in the current window the same.
        vii. Checking if the number of replacements needed is less than or equal to k,
            if yes then we update the max length of the substring.
        viii. If not, then we shrink the window by moving the left pointer forward,
            and decrementing the frequency of the character at the left pointer in the unordered_map.
        ix. Finally, we return the max length of the substring found.
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len = 0;
        unordered_map<char, int> m;
        int left = 0;
        int max_freq = 0;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];
            m[c]++;

            max_freq = max(max_freq, m[c]);

            int window_size = right - left + 1;
            int replacement = window_size - max_freq;

            if(replacement <= k)
                max_len = max(window_size, max_len);
            else {
                m[s[left]]--;
                left++;
            }

        }

        return max_len;
    }
};

/***************************************************************************************************************/
/*
    Solution Approach: Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1) (Because the unordered_map will have at most 26 characters for uppercase English letters)
    N = length of the input string s

    Explanation:-
        i. Same as above using left and right pointer pointing at the starting position of the string s i.e. 0
        ii. what different we are doing here is,
            we are checking is from the current window of strings,
                how many characters we need to replace to make all the characters in the current window the same.
            And based on that we are changing the left pointer and also the frequency count of the character.
        iii. Then we are updating and storing the size of the current window of strings to work with.
        iv. Finally, we return the max length of the substring found.
*/
class Solution {
    private:
        int getMaxValues(const unordered_map<char, int>& count) {
            int max_val = 0;

            for (auto const&[key, val] : count)
                max_val = max(max_val, val);

            return max_val;
        }

    public:
        int characterReplacement(string s, int k) {
            unordered_map<char, int> count;
            int size = 0;
            int l = 0;

            for (int r = 0; r < s.size(); r++) {
                count[s[r]]++;

                while (((r - l + 1) - getMaxValues(count)) > k) {
                    count[s[l]]--;
                    l++;
                }

                size = max(size, r - l + 1);
            }

            return size;
        }
};
