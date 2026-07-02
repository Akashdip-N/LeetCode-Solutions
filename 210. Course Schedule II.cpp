/*
    https://leetcode.com/problems/course-schedule-ii/
*/
/*
    Solution Approach:- Using DFS (Depth First Search)

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)

    V = number of vertices (courses)
    E = number of edges (prerequisites)

    ----------------------------------------------------------------
    This problem is a continuation of pr 207. Course Schedule.
    (https://leetcode.com/problems/course-schedule/)
    ----------------------------------------------------------------

    Explanation:-
        * The solution is same as pr 207. Course Schedule,
            but we need to return the order of courses.
        * That's why we are using a vector to store the order of courses
            but that will be in reverse order, so we need to reverse it before returning.
        * That's why are reversing the result vector before returning.
*/
class Solution {
public:
    bool dfs(
        int node,
        unordered_map<int, vector<int>>& adj,
        unordered_set<int>& visited,
        unordered_set<int>& dfsVisited,
        vector<int>& orderStack
    ) {
        visited.insert(node);
        dfsVisited.insert(node);

        for(auto it : adj[node]) {
            if(visited.find(it) == visited.end()) {
                if(dfs(it, adj, visited, dfsVisited, orderStack))
                    return true;
            }
            else if(dfsVisited.find(it) != dfsVisited.end())
                return true;
        }

        dfsVisited.erase(node);
        orderStack.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto it : prerequisites)
            adj[it[1]].push_back(it[0]);

        unordered_set<int> visited;
        unordered_set<int> dfsVisited;
        vector<int> result;

        for(int i = 0; i < numCourses; i++){
            if(visited.find(i) == visited.end()) {
                if(dfs(i, adj, visited, dfsVisited, result))
                    return {};
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
