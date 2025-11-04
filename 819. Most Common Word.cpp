/*
    https://leetcode.com/problems/most-common-word
*/
/*
    Solution Approach:- Using HashMap

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = Length of paragraph

    Explanation:
        * Create a hashmap to store the banned words for O(1) lookup.
        * Traverse through the paragraph character by character,
            for each character:
                - If it's an alphabet, convert it to lowercase and append it to the current word.
                - If it's a non-alphabet character,
                    check if the current word is not empty and not in the banned list,
                        If valid, increment its count in another hashmap and
                            update the maximum count if necessary.
                - Clear the current word for the next iteration.
        * After the loop, check for the last word in case the paragraph ends with an alphabet.
        * Finally, iterate through the word count hashmap to find and
            return the word with the maximum
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> bannedwords;
        for (const string& word : banned)
            bannedwords[word]++;

        unordered_map<string, int> words;
        string word;
        int maxcount = 0;

        for (char& ch : paragraph) {
            if (isalpha(ch))
                word += tolower(ch);
            else {
                if (!word.empty() && bannedwords.find(word) == bannedwords.end()) {
                    words[word]++;
                    maxcount = max(maxcount, words[word]);
                }

                word.clear();
            }
        }

        // Last word
        if (!word.empty() && bannedwords.find(word) == bannedwords.end()) {
            words[word]++;
            maxcount = max(maxcount, words[word]);
        }

        for (const auto& word : words) {
            if (word.second == maxcount)
                return word.first;
        }

        return "";
    }
};
