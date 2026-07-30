/*
    https://leetcode.com/problems/shift-2d-grid/
*/
/*
    Solution Approach:- Using flattening of 2D Array to 1D Array

    Time Complexity:- O(M*N)
    Space Complexity:- O(M*N)
    M = Number of Rows in the Grid
    N = Number of Columns in the Grid

    Intuition:-
        * Flattening the 2D array into 1D array then calculating the position.
        Ex:-

        arr = [
                1 2 3
                4 5 6
                7 8 9
              ]
            Flattened Array:- [1,2,3,4,5,6,7,8,9]

        * Using mod value to calculate the new position of the element.

    Explanation:-
        * Storing the number of rows and columns in the grid in m and n variable
        * Calculating the total number of elements in the grid.
        * Calculating the effective number of shifts needed by taking k modulo total.
        Ex:-
            If k = 10,
            M = 3, N = 3
            Total = 9

            Effective Shifts = 10 % 9 = 1
        * Base case:- if the effective shifts is 0, then return the original grid.
        * Creating a new 2D array to store the shifted grid.
        * Iterating through each index of the grid, and performing the following steps:
            * Calculating the flattened index of the current element.
            * Calculating the new flattened index after shifting,
                by adding the flattened index and the effective shifts,
                    and taking the modulo with the total number of elements.
            * Calculating the new row and column indices from the new flattened index.
            * Storing the current element in the new position in the new 2D array.
        * After iterating through all the elements,
            returning the new 2D array as the result.
*/
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        if (k == 0) return grid;

        vector<vector<int>> res(m, vector<int>(n, -1));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int flatIndex = r * n + c;

                int newFlatIndex = (flatIndex + k) % total;

                int newRow = newFlatIndex/n;
                int newCol = newFlatIndex%n;

                res[newRow][newCol] = grid[r][c];
            }
        }

        return res;
    }
};
