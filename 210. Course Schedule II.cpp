/*
    https://leetcode.com/problems/course-schedule-ii/
*/
/*
    Solution Approach:- Using DFS + Topological Sort

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)

    V = Number of vertices (courses)
    E = Number of edges (prerequisites)

    Intuition:-
        - Same as Pr. 207. Course Schedule (https://leetcode.com/problems/course-schedule/)
        - But here the extra part is we have to keep a track of the order in which
            the courses can be completed.

    Explanation:-
        * Using the same solution as Pr. 207 Course Schedule.
        * But if we detect a cycle, we return an empty vector.
        * Else we keep on adding the visited course in the vector,
            and we return it.
        * Since, we have to start the course from the last course,
            we reverse the vector and return it.
*/
class Solution {
public:
    bool dfs(
        int currentCourse,
        unordered_map<int, vector<int>>& adj,
        unordered_set<int>& visited,
        unordered_set<int>& dfsVisited,
        vector<int>& orderStack
    ) {
        visited.insert(currentCourse);
        dfsVisited.insert(currentCourse);

        for(auto course : adj[currentCourse]) {
            if(visited.find(course) == visited.end()) {
                if(dfs(course, adj, visited, dfsVisited, orderStack))
                    return true;
            }
            else if(dfsVisited.find(course) != dfsVisited.end())
                return true;
        }

        dfsVisited.erase(currentCourse);
        orderStack.push_back(currentCourse);
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
