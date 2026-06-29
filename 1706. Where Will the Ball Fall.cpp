/*
    https://leetcode.com/problems/where-will-the-ball-fall
*/
/*
    Solution Approach:- Using Simulation

    Time Complexity: O(M*N)
    Space Complexity: O(N)
    M = number of rows in the grid
    N = number of columns in the grid

    Explanation:-
        * For each value in the grid we are checking the adjacent value
            and if the adjacent value is same as the current value then we can move to that position
                because it's forming a V-shaped pattern and the ball can move to that position.
            and if the adjacent value is different from the current value then we cannot move to that position
            and we will break the loop and return -1 for that column.

    Ex:-
        We have this grid:
        [ *1,  1,  1, -1, -1]
        [  1, *1,  1, -1, -1]
        [ -1, -1,*-1,  1,  1]
        [  1, *1,  1,  1, -1]
        [ -1, -1,*-1, -1, -1]

        * So if we drop the ball from pos(0,0) it would finally come down to pos(4, 2)
            and would come out and the result would be 1;
        * If we drop the call from pos(0, 1) it would come to pos(1, 3)
            and would get stuck in a V-shaped pattern and the result would be -1;
*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> answer(cols, -1);

        for (int i = 0; i < cols; i++) {
            int row = 0;
            int col = i;

            while (row < rows) {
                int grid_val = grid[row][col];

                if (grid_val == -1) {
                    // If the current cell is in the left most column or
                    // If the value of the left adjacent cell is 1
                    // then break the loop because the ball will get stuck in a V-shaped pattern
                    if (col == 0 || grid[row][col - 1] == 1) break;
                    // else going to the left adjacent cell and moving down to the next row
                    else {
                        col--;
                        row++;
                    }
                }
                else {
                    // If the current cell is in the right most column or
                    // If the value of the right adjacent cell is -1
                    // then break the loop because the ball will get stuck in a V-shaped pattern
                    if (col == (cols - 1) || grid[row][col + 1] == -1) break;
                    // else going to the right adjacent cell and moving down to the next row
                    else {
                        col++;
                        row++;
                    }
                }
            }

            // If the ball has reached the last row, then it means it has successfully fallen through the grid
            if (row == rows)
                answer[i] = col;
        }

        return answer;
    }
};
