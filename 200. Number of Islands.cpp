/*
    https://leetcode.com/problems/number-of-islands/
*/
/*
    Solution Approach:- Using DFS (Depth First Search)

    Time Complexity: O(M*N)
    Space Complexity: O(M*N)

    M = number of rows
    N = number of columns

    Explanation:-
        * Using set to store the visited cell location,
            using the following formula to store the cell location in set
                cell_location = row * number_of_columns + column

        * Iterating through each cell in the grid.
        * If we encounter a '1' (land) that hasn't been visited,
            we increment the island count and perform a DFS
                to mark all connected land cells as visited.

        * Inside the helper function,
            i. Checking if we have encountered a '0' (water)
                or if the cell has already been visited,
                    returning from the function.
            ii. Inserting the current cell location into the visited set.
            iii. Recursively calling the helper function for all four adjacent cells
                (up, down, left, right).
*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, set<int>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Check for out of bounds
        if (r < 0 || c < 0 || r >= rows || c >= cols) return;

        // Check if it's water or already visited
        if (grid[r][c] == '0' || visited.find(r * cols + c) != visited.end()) return;

        visited.insert(r * cols + c);

        dfs(grid, r + 1, c, visited);
        dfs(grid, r - 1, c, visited);
        dfs(grid, r, c + 1, visited);
        dfs(grid, r, c - 1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        set<int> visited;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && visited.find(r * cols + c) == visited.end()) {
                    islandCount++;
                    dfs(grid, r, c, visited);
                }
            }
        }

        return islandCount;
    }
};
