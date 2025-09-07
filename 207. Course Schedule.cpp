/*
    https://leetcode.com/problems/course-schedule/
*/
/*
    Solution Approach:- Using DFS to detect cycle in a directed graph

    Time Complexity: O(V + E)
    Space Complexity: O(V + E) + O(V) + O(V)
    V = Number of vertices
    E = Number of edges

    Explanation:-
        i. Create an adjacency list from the prerequisites.
        ii. Create two sets, one for visited nodes and one for nodes in the current DFS path.
        iii. For each unvisited node, perform a DFS.
        iv. If we encounter a node that is already in the current DFS path,
            a cycle is detected, and we return false.
        v. If we complete the DFS without finding a cycle, we return true.
*/
class Solution {
public:
    // Function to perform DFS and detect cycles
    bool dfs(
        int node,
        unordered_map<int, vector<int>>& adj,
        set<int>& visited,
        set<int>& dfsVisited
    ) {
        visited.insert(node);
        dfsVisited.insert(node);

        for(auto it : adj[node]) {
            if(visited.find(it) == visited.end()) {
                if(dfs(it, adj, visited, dfsVisited))
                    return true;
            }
            else if(dfsVisited.find(it) != dfsVisited.end())
                return true;
        }

        dfsVisited.erase(node);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto it : prerequisites)
            adj[it[1]].push_back(it[0]);

        set<int> visited;
        set<int> dfsVisited;

        for(int i = 0; i < numCourses; i++)
            if(visited.find(i) == visited.end())
                if(dfs(i, adj, visited, dfsVisited))
                    return false;

        return true;
    }
};
