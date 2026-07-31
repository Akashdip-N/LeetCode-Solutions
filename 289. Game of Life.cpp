/*
    https://leetcode.com/problems/game-of-life
*/
/*
    Solution Approach:- Using Unique Markers

    Time Complexity: O(N*M)
    Space Complexity: O(1)
    N = number of rows
    M = number of columns

    Intuition:-
        * We have a 2D matrix, and we have to check the neighbouring cells for each cell,
        * BUT THE CATCH IS WE CAN'T USE ANY EXTRA SPACE,
        * So we use a unique marker to mark the cells that are going to change their state,
            and then in the second pass, we change the unique markers to their final state.

        Using this similar condition:-
            0 -> 1 (if neighbourcount == 3(1))                       10
            0 -> 0                                                   11
            1 -> 1 (neighbourcount => 2 && neighbourcount <= 3)      12
            1 -> 0 (neighbourcount < 2 (1) || neighbourcount > 3)    13

    Explanation:-
        * Using a helper function to count the number of alive neighbours for that specific cell.
        * Then we are iterating through the whole matrix and checking for each cell the following:-
            i. The number of live cells.
            ii. What's the current state of the cell,
                    and then based on number of live cells updating the state of the cell to a unique marker.
        * Then we are updating the board to it's original state based on the unique markers we used in the first pass.
*/
class Solution {
public:
    int countNeighbour(vector<vector<int>>& board, int r, int c){
        int row = board.size();
        int col = board[0].size();
        int count = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;

                int nr = r + i;
                int nc = c + j;

                if (nr >= 0 && nr < row && nc >= 0 && nc < col) {
                    // Originally Alive: Cells that started as '1' are now either 1, 12, or 13
                    if (board[nr][nc] == 1 || board[nr][nc] == 12 || board[nr][nc] == 13)
                        count++;
                }
            }
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int neighbours = countNeighbour(board, i, j);

                if(board[i][j] == 0){
                    if(neighbours == 3)
                        board[i][j] = 10; // State 10: 0 -> 1
                    else
                        board[i][j] = 11; // State 11: 0 -> 0
                }
                else
                    if(board[i][j] == 1){
                        if(neighbours >= 2 && neighbours <= 3)
                            board[i][j] = 12; // State 12: 1 -> 1
                        else if(neighbours < 2 || neighbours > 3)
                            board[i][j] = 13; // State 13: 1 -> 0
                }
            }
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 10 || board[i][j] == 12)
                    board[i][j] = 1; // Ends up ALIVE
                else if(board[i][j] == 11 || board[i][j] == 13)
                    board[i][j] = 0; // Ends up DEAD
            }
        }
    }
};
