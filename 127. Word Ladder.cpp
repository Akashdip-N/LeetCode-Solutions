/*
    https://leetcode.com/problems/word-ladder
*/
/*
    Solution Approach: Using BFS to find the shortest path from beginWord to endWord.

    Time Complexity: O(N * M^2)
    Space Complexity: O(N * M^2)
    N = number of words in the wordList
    M = length of the words

    Explanation:
        * Since it has been told to find the shortest path,
            it means we have to use BFS.
        * We are creating a map of patterns to words.
            * For example, if we have the word "hot", we will create the following patterns
                * "*ot" -> ["hot"]
                * "h*t" -> ["hot"]
                * "ho*" -> ["hot"]
            * This will help us to find the neighbors of a word in O(1) time
        * We will use a queue to perform BFS and a set to keep track of visited words
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool hasEndWord = false;
        for (const string& word : wordList) {
            if (word == endWord) {
                hasEndWord = true;
                break;
            }
        }

        if (!hasEndWord)
            return 0;

        // Adjacent list to store the patterns and their corresponding words
        unordered_map<string, vector<string>> m;
        wordList.push_back(beginWord);

        // Create a map of patterns to words
        for (string word : wordList) {
            for (int j = 0; j < word.size(); j++) {
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                m[pattern].push_back(word);
            }
        }

        unordered_set<string> visit;
        visit.insert(beginWord);

        // BFS to find the shortest path from beginWord to endWord
        queue<string> q;
        q.push(beginWord);

        int res = 1;

        while (!q.empty()) {
            int qSize = q.size();

            // Using qsize as variable because the size of the queue will
            //      change dynamically as we push new words into the queue
            for (int i = 0; i < qSize; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return res;

                for (int j = 0; j < word.size(); j++) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (string newWord : m[pattern]) {
                        if (visit.find(newWord) == visit.end()) {
                            visit.insert(newWord);
                            q.push(newWord);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
