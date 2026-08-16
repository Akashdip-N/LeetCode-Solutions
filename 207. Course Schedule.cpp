/*
    https://leetcode.com/problems/course-schedule/
*/
/*
    Solution Approach:- Using DFS to detect cycle in a directed graph

    Time Complexity: O(V + E)
    Space Complexity: O(V + E) + O(V) + O(V)
    V = Number of vertices
    E = Number of edges

    Intuition:-
        - So have been given a list of courses, and a list of prerequisites for each course.
        - We have to check if it's possible to finish all the courses.
        - So we have to only make sure that we don't have any cycle in the graph,
            because if we have a cycle, then we can't finish all the courses.
                then we return false, else we return true.
        Ex:-
            numCourses = 2
            prerequisites = [[1,0],[0,1]]

            1 -> 0, 0 -> 1
            So we have a cycle, so we can't finish all the courses, so we return false.

    Explanation:-
        i. Main function:-
            * Creating an adjacency list based on the prerequisites.
                Example:-
                    numCourses = 4
                    prerequisites = [[1,0],[2,0],[3,1],[3,2]]

                    adj = {
                        0: [1, 2],
                        1: [3],
                        2: [3]
                    }

            * Iterating through 0 to numCourses - 1,
                and for each course, checking if the course is already visited or not.
            * Then we call the helper function to check cycle in the graph using DFS.
            * If the call returns true, that means there is a cycle in the graph, so we return false.
            * If there are no cycles in the graph, then we return true,
                that means we can finish all the courses.

        ii. Helper function:-
            * Passing the following parameters to the helper function:-
                i. Current course
                ii. Adjacency list which maps the course to its prerequisites
                iii. Visited set to keep track of the visited courses
                iv. DFS visited set to keep track of the courses in the current DFS path
            * Iterating through each prerequisites of the current course,
                and checking if we have already visited that course or not.
            * If we haven't visited that course,
                then we call the helper function recursively,
                    and if the call returns true,
                        (that means there is a cycle in the graph),
                            so we return true.
            * If we have already visited that course,
                then we check if that course is in the current DFS path or not,
                    if it is, then we have a cycle in the graph,
                        (
                            That means to finish the current course,
                            we need to finish the course from which we came to the current course
                        )
                        so we return true.

            ---------------------------------------------------------------------------------
                Ex:-
                    numCourses = 2
                    prerequisites = [[1,0],[0,1]]

                    adj = {
                        0: [1],
                        1: [0]
                    }

                    Iteration 1:-
                        currentCourse = 0
                        visited = {0}
                        dfsVisited = {0}

                        Iterating through prereq of course 0, which is 1,
                            calling dfs(1, adj, visited, dfsVisited)

                    Iteration 2:-
                        currentCourse = 1
                        visited = {0, 1}
                        dfsVisited = {0, 1}

                        Iterating through prereq of course 1,
                            which is 0,

                            Checking if 0 is in the visited set,
                                and it's present.
                            Then checking if 0 is in the dfsVisited set,
                                and it's present.

                    So, we have a cycle in the graph, so we return true.
            ---------------------------------------------------------------------------------
            * When we have done iterating through all the prerequisites of the current course,
                we remove it from the dfsVisited set,
            * Since we have finished exploring all the prerequisites of the current course,
                we return false, that means there is no cycle in the graph.
*/
class Solution {
public:
    bool dfs(
        int currentCourse,
        unordered_map<int, vector<int>>& adj,
        set<int>& visited,
        set<int>& dfsVisited
    ) {
        visited.insert(currentCourse);
        dfsVisited.insert(currentCourse);

        for(auto courses : adj[currentCourse]) {
            if(visited.find(courses) == visited.end()) {
                if(dfs(courses, adj, visited, dfsVisited))
                    return true;
            }
            else if(dfsVisited.find(courses) != dfsVisited.end())
                return true;
        }

        dfsVisited.erase(currentCourse);
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
