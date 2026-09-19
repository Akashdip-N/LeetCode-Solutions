/*
    https://leetcode.com/problems/word-search/
*/
/*
    Solution Approach:- Using DFS and Backtracking

    Time Complexity:- O(N * M * 3^L)
    Space Complexity:- O(L)
    N = number of rows
    M = number of columns
    L = length of the word

    Intuition:-
        - We have been given a grid of characters and a word.
        - We have to check if we can find the word with the characters in the grid.
        - These are the following conditions which we need to follow:-
            i. We can start from any cell in the grid.
            ii. We can't use the same cell twice.
            iii. We can move in 4 directions (up, down, left, right).

        - We would use DFS to traverse the grid and
            backtracking to keep track of all the cells that we have already visited.
        - We would start from each cell in the grid and
            check if we can find the word starting from that cell.

    Explanation:-
        * First we are creating two variables rows and cols
            to store the number of rows and columns in the grid.

        exists() function:-
            * Iterating through each cell in the grid and
                checking if the first character of the word matches the character in the cell.
            * If it does then we call the helper function
                to check if we can find the word starting from that cell.
            * And if we find the word then we return true.
            * Else by default we return false.

        dfs() function:-
            * Taking the following parameters:-
                i. The board of characters
                ii. The word we are looking for
                iii. The row and col in which we would the first character of the word
                iv. Current index of the character in the word we are looking for.

            * Base case:-
                i. If the current index is same as the length of the word,
                    that means we have found the word and we return true.
                ii. If the current row and col is out of bounds or
                    the character in the cell is not same as the character in the word,
                        that means we can't find the word and we return false.

            * Storing the current cell into a temp variable,
                and marking the current cell as visited by changing it to '#'.
                (
                    By using this we can avoid using any other data structure
                    to keep track of the visited cells.
                )
            * Then calling the same dfs function for the 4 directions (up, down, left, right)
                and checking if we can find the word in any of the directions,
                    and store the result in a variable found.
            * Finally changing back the current cell with it's original value
                that is stored in the temp variable.
            * Returning the value of found.
*/
class Solution {
    private:
        int rows, cols;
        bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
            if (index == word.length())
                return true;

            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index])
                return false;

            char temp = board[r][c];
            board[r][c] = '#';

            bool found = dfs(board, word, r + 1, c, index + 1) ||
                        dfs(board, word, r - 1, c, index + 1) ||
                        dfs(board, word, r, c + 1, index + 1) ||
                        dfs(board, word, r, c - 1, index + 1);

            board[r][c] = temp;
            return found;
        }

    public:
        bool exist(vector<vector<char>>& board, string word) {
            rows = board.size();
            cols = board[0].size();

            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    if (board[i][j] == word[0])
                        if (dfs(board, word, i, j, 0))
                            return true;

            return false;
        }
};
