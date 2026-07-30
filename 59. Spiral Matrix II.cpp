/*
    https://leetcode.com/problems/spiral-matrix-ii/
*/
/*
    Solution Approach:- Using Simulation

    Time Complexity: O(N*N)
    Space Complexity: O(N*N)
    N = input integer

    Intuition:-
        - Creating a 2D vector of size n x n and initializing it with 0.
        - Using four pointers to keep track of the boundaries of the matrix.
        - Filling the matrix in a spiral order by iterating through the boundaries and updating the pointers accordingly.
        - The process continues until all the elements are filled in the matrix.
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        int val = 1;
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; ++col)
                res[top][col] = val++;
            top++;

            for (int row = top; row <= bottom; ++row)
                res[row][right] = val++;
            right--;

            for (int col = right; col >= left; --col)
                res[bottom][col] = val++;
            bottom--;

            for (int row = bottom; row >= top; --row)
                res[row][left] = val++;
            left++;
        }

        return res;
    }
};
