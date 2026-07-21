/*
    https://leetcode.com/problems/evaluate-division/
*/
/*
    Solution Approach:- Using DFS (Depth First Search)

    Time Complexity: O(E + Q * (V + E))
    Space Complexity: O(V + E + Q)

    E = number of edges in the graph
    V = number of vertices in the graph
    Q = number of queries

    Explanation:-
        * We have to find the two variables given in the query from the equations and values given.
        * Using graph to represent the equations and values.

        i. calcEquation function:-
            * Creating a graph where each equation is represented
                as an edge between two variables with the value as the weight of the edge.
            * And storing the inverse of the value as the weight of the edge in the opposite direction.
            Ex:-
                equations = [["a","b"],["b","c"]]
                values = [2.0,3.0]

                graph representation:
                    a --(2.0)--> b
                    b --(1/2.0)--> a
                    b --(3.0)--> c
                    c --(1/3.0)--> b

            * Creating a result vector same size as the queries vector to store the results of each query.
            * Iterating through each query and checking if the two variables are present in the graph.
                * If not, we push -1.0 to the result vector.
                * If yes, we perform a DFS to find the path from
                    the first variable to the second variable and
                        store the value of the path in the result vector.
            * Returning the result vector after processing all the queries.

        ii. dfs function:-
            * Taking the numerator, denominator, graph and visited set as input.
            * If the numerator is equal to the denominator, we return 1.0 as the result.
            * Marking the numerator as visited to avoid cycles in the graph.
            * Iterating through the neighbors of the numerator in the graph.
                * If the neighbor is not visited, we perform a DFS on the neighbor.
                    * If the result of the DFS is not -1.0,
                        we return the product of the weight of the edge and the result of the DFS.
            * If no path is found, we return -1.0 as the result.
*/
class Solution {
    private:
        double dfs(
            const string& curr,
            const string& target,
            unordered_map<string, unordered_map<string, double>>& graph,
            unordered_set<string>& visited
        ){
            if (curr == target)
                return 1.0;

            visited.insert(curr);

            for (const auto& [next, weight] : graph[curr]) {
                if (!visited.count(next)) {
                    double result = dfs(next, target, graph, visited);

                    if (result != -1.0)
                        return weight * result;
                }
            }

            return -1.0;
        }

    public:
        vector<double> calcEquation(
            vector<vector<string>>& equations,
            vector<double>& values,
            vector<vector<string>>& queries
        ){
            // Creating a graph with adjacency list representation using unordered_map
            unordered_map<string, unordered_map<string, double>> graph;

            for (int i = 0; i < equations.size(); ++i) {
                const string& u = equations[i][0];
                const string& v = equations[i][1];
                double val = values[i];

                // Add the edge u -> v with weight val
                graph[u][v] = val;

                // Add the edge v -> u with weight 1/val
                graph[v][u] = 1.0 / val;
            }

            // Creating result vector same size as the queries vector
            vector<double> results;
            results.reserve(queries.size());

            for (const auto& q : queries) {
                const string& start = q[0];
                const string& end = q[1];

                if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
                    results.push_back(-1.0);
                else{
                    unordered_set<string> visited;
                    results.push_back(dfs(start, end, graph, visited));
                }
            }

            return results;
        }
};
