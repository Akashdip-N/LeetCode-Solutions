/*
    https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
*/
/*
    Solution Approach:- Using Depth First Search (DFS)

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of stones

    Explanation:-
        * First creating an adjacency list of the stones,
            where each stone is connected to other stones in the same row or column.
        * Ex:- [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
            The adjacency list will be:
                0: [20001, 20002]
                20001: [0, 1, 2]
                20002: [0, 1, 2]
                20003: [2]
                1: [20001, 20002]
                2: [20002, 20003]
        * Then, we will perform a DFS on the adjacency list to find the number of connected components.
        * Finally, we will return the number of stones - number of connected components.
*/
class Solution {
    private:
        void dfs(
            int u,
            unordered_map<int, vector<int>>& adj,
            unordered_set<int>& visited
        ){
            visited.insert(u);

            for (int neighbor : adj[u])
                if (visited.find(neighbor) == visited.end())
                    dfs(neighbor, adj, visited);
        }

    public:
        int removeStones(vector<vector<int>>& stones) {
            unordered_map<int, vector<int>> adj;

            for (auto& stone : stones) {
                int r = stone[0];
                int c = stone[1] + 20001;
                adj[r].push_back(c);
                adj[c].push_back(r);
            }

            unordered_set<int> visited;
            int components = 0;

            for (auto& stone : stones) {
                int r = stone[0];

                if (visited.find(r) == visited.end()) {
                    dfs(r, adj, visited);
                    components++;
                }
            }

            return stones.size() - components;
        }
};
