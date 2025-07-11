/*
    https://leetcode.com/problems/reverse-words-in-a-string/description/
*/
/*
    Solution Approach: Two Pointers Approach

    Time Complexity: O(n)
    Space Complexity: O(n)

    Explanation:
        - First, trimming the leading and trailing spaces.
        - Iterating from the end of the string to the beginning.
        - For each word found, appending it to the result string along with a space.
        - Moving the right pointer to the end of the next word.
        - Skipping spaces between words.
        - At the end, removing any trailing space from the result.
        - Finally, returning the result string.
*/
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int size = s.size();
        int left = 0, right = size - 1;

        while(left < size && s[left] == ' ')
            left++;

        while(right >= 0 && s[right] == ' ')
            right--;

        while(left <= right) {
            int end = right;

            // Finding the starting index of the word
            while(end >= left && s[end] != ' ')
                end--;

            // Adding the word to the result
            result += s.substr(end + 1, right - end) + ' ';

            // Moving the right pointer to the end of the next word
            right = end - 1;

            // Skipping spaces before the next word
            while(right >= left && s[right] == ' ')
                right--;
        }

        // Removing the trailing space if exists
        if(!result.empty() && result.back() == ' ')
            result.pop_back();

        return result;
    }
};
