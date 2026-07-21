/*
    https://leetcode.com/problems/cracking-the-safe/
*/
/*
    Solution Approach:- Using DFS & Backtracking

    Time Complexity:- O(K^N)
    Space Complexity:- O(N * K^N)
    N = length of the password
    K = number of digits

    Intuition:-
        * Problem is to find the shortest string that contains all possible combinations of length n using digits from 0 to k-1.
        * Using DFS to explore all possible combinations of length n.

    Explanation:-
        * Creating a string startNode of length n-1 filled with '0's.
        * Creating an unordered_set visited to keep track of visited combinations.
        * Creating an empty string result to store the final result.
        * Calling the dfs function with startNode, k, visited and result.
        * In the dfs function, iterating over all possible digits from 0 to k-1.
        * For each digit, creating a new edge by appending the digit to the current node.
            If the edge is not visited,
                marking it as visited and calling dfs recursively with the new edge
                    (excluding the first character) and appending the digit to the result.
        * Finally, returning the result concatenated with startNode to get the final answer.
*/
class Solution {
    private:
        void dfs(
            const string& node,
            int k,
            unordered_set<string>& visited,
            string& result
        ){
            for (int i = 0; i < k; ++i) {
                string edge = node + to_string(i);

                if (visited.find(edge) == visited.end()) {
                    visited.insert(edge);

                    // Passing substring excluding the first character
                    dfs(edge.substr(1), k, visited, result);

                    result += to_string(i);
                }
            }
        }

    public:
        string crackSafe(int n, int k) {
            if (n == 1 && k == 1)
                return "0";

            // Creating a string of length n-1 filled with '0's
            string startNode(n - 1, '0');
            unordered_set<string> visited;
            string result = "";

            dfs(startNode, k, visited, result);

            return result + startNode;
        }
};
