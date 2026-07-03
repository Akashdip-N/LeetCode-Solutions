/*
    https://leetcode.com/problems/alien-dictionary (PREMIUM)
    https://neetcode.io/problems/foreign-dictionary/question
*/
/*
    Solution Approach:- Using Topologica Sort and DFS

    Time Complexity:- O(N + E)
    Space Complexity:- O(N + E)
    N = number of unique characters in the words
    E = number of edges in the graph (dependencies between characters)

    Problem Statement:-
        * We have been give a list of words sorted in lexicographical order.
        * We have to find the order of characters in the alien language.

        Ex:-
            Input: words = ["hrn","hrf","er","enn","rfnn"]
            Output: "herfn"

    Explanation:-
        * Creating adjacency list for each of the unqiue characters present in the list of words.
        * Then we running a for loop from the first word to the second last word.
        * In the for loop we are comparing the current word with the next word.
        * Checking if the size of the first word > size of the second word,
                and the first word is a prefix of the second word, then it is invalid.
            Ex:- word1 = "abcd", word2 = "abc" [Invalid],
                because word2 should come before word1 in lexicographical order.
        * Then checking and storing the first mismatch of characters between the two words,
            and creating a directed edge from the first character to the second character.

            For the input words = ["hrn","hrf","er","enn","rfnn"]
            The adjacency list will look like this:-
                h -> e
                r -> n
                n -> f
                f
                e -> r

        * Then we are running a DFS on each of the unique characters to check for cycles in the graph.
            * If a cycle is detected,
                then it is invalid and we return an empty string.
            * If no cycle is detected,
                then we are storing the characters in post-order.
        * Finally, we are reversing the post-order to get the correct topological sorting of the characters.
*/
class Solution {
    private:
        bool dfs(
            char c,
            unordered_map<char, unordered_set<char>>& adj,
            unordered_map<char, bool>& visit,
            string& res
        ) {
            // Detecting cycles in the graph
            if (visit.find(c) != visit.end())
                return visit[c];

            visit[c] = true;

            for (char ch : adj[c])
                if (dfs(ch, adj, visit, res))
                    return true; // Cycle detected in a neighbor

            visit[c] = false; // Mark as visited (off the current recursion path)
            res.push_back(c); // Post-order collection
            return false;
        }

    public:
        string foreignDictionary(vector<string>& words) {
            unordered_map<char, unordered_set<char>> adj;

            // Creating adjacency list for each unique character from the list of words
            for (const string& w : words) {
                for (char c : w)
                    if (adj.find(c) == adj.end())
                        adj[c] = unordered_set<char>();
            }

            // Build dependencies by comparing adjacent words
            for (size_t i = 0; i < words.size() - 1; ++i) {
                const string& w1 = words[i];
                const string& w2 = words[i + 1];
                size_t minLen = min(w1.length(), w2.length());

                // Check for invalid prefix rule (e.g., "abcd" comes before "abc")
                if ((w1.length() > w2.length()) && (w1.substr(0, minLen) == w2.substr(0, minLen)))
                    return "";

                // Find the first mismatching character to define a directed edge
                for (size_t j = 0; j < minLen; ++j) {
                    if (w1[j] != w2[j]) {
                        adj[w1[j]].insert(w2[j]);
                        break;
                    }
                }
            }

            unordered_map<char, bool> visit;
            string res = "";

            // Perform DFS on every character to check for cycles and extract order
            for (const auto& pair : adj) {
                char c = pair.first;
                if (dfs(c, adj, visit, res))
                    return "";
            }

            // Reverse post-order to get correct topological sorting
            reverse(res.begin(), res.end());
            return res;
        }
};
