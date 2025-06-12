/*
    https://leetcode.com/problems/check-if-the-sentence-is-pangram
*/
/*
    Solution Approach: Using a Hash Map
    Time Complexity: O(n), n is the length of the sentence.

    Explanation:
        * Storing all the characters in a hash map to count their occurrences.
        * If the size of the hash map is less than 26,
            it means not all letters are present, then return false.
                else return true.
*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::unordered_map<char, int> charCount;
        for (char c : sentence)
            charCount[c]++;

        if (charCount.size() < 26)
            return false;

        return true;
    }
};
