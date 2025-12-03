/*
    https://leetcode.com/problems/find-if-path-exists-in-graph
*/
/*
    Solution Approach:- Using DFS and Recursion

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
    V = Number of vertices
    E = Number of edges

    Explanation:
        * Using DFS and recursion to traverse the graph.
        * Base case:
            If the source is same as destination, if yes return true.
        * We store all the edges and their connections in an adjacency list.
        * We start from the source node and explore all its neighbors recursively.
        * If we reach the destination node during our traversal, we return true.
        * If we exhaust all possibilities without reaching the destination,
            we return false.
*/
class Solution {
public:
    bool dfs(
            int node,
            int destination,
            vector<vector<int>>& graph,
            vector<bool>& visited
    ) {
        if (node == destination)
            return true;

        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, graph, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;

        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        return dfs(source, destination, graph, visited);
    }
};

/***************************************************************************************/
/*
    Solution Approach:- Using BFS and Queue

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
    V = Number of vertices
    E = Number of edges

    Explanation:
        * Using BFS and queue to traverse the graph.
        * Base case:
            If the source is same as destination, if yes return true.
        * We store all the edges and their connections in an adjacency list.
        * We start from the source node and explore all its neighbors.
        * If we reach the destination node during our traversal, we return true.
        * If we exhaust all possibilities without reaching the destination,
            we return false.
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;

        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

/***************************************************************************************/
/*
    Solution Approach:- Using DFS and Stack

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)
    V = Number of vertices
    E = Number of edges

    Explanation:
        * Using DFS and stack to traverse the graph.
        * Base case:
            If the source is same as destination, if yes return true.
        * We store all the edges and their connections in an adjacency list.
        * We start from the source node and explore all its neighbors using stack.
        * If we reach the destination node during our traversal, we return true.
        * If we exhaust all possibilities without reaching the destination,
            we return false.
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;

        vector<vector<int>> graph(n);

        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        stack<int> s;
        s.push(source);
        visited[source] = true;

        while(!s.empty()){
            int node = s.top();
            s.pop();

            if(node == destination)
                return true;

            for(int neighbor : graph[node]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }

        return false;
    }
};
