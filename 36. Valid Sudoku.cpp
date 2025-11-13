/*
    https://leetcode.com/problems/valid-sudoku
*/
/******************************** OWN SOLUTION *************************************/
/*
    Solution Approach:- Using HashMap and HashSet

    Time Complexity: O(1)
    Space Complexity: O(1)
    Since, the board size is fixed (9x9).

    Explanation:
        * Using a HashMap to store the board values.
        * Using a HashSet to check for duplicates in rows, columns, and 3x3 sub-boxes.
        * Iterate through each row, and column to check for duplicates.
        * And at last, iterate through each 3x3 sub-box to check for duplicates.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, char>> m;
        unordered_set<char> seen;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                m[i][j] = board[i][j];

        for (int r = 0; r < 9; r++) {
            seen.clear();
            for (int c = 0; c < 9; c++) {
                char val = m[r][c];

                if (val == '.')
                    continue;

                if (seen.count(val))
                    return false;

                seen.insert(val);
            }
        }

        for (int c = 0; c < 9; c++) {
            seen.clear();
            for (int r = 0; r < 9; r++) {
                char val = m[r][c];

                if (val == '.')
                    continue;

                if (seen.count(val))
                    return false;
                seen.insert(val);
            }
        }

        // Checking 3x3 sub-boxes
        for (int br = 0; br < 3; br++) {
            for (int bc = 0; bc < 3; bc++) {
                seen.clear();
                for (int r = br * 3; r < br * 3 + 3; r++) {
                    for (int c = bc * 3; c < bc * 3 + 3; c++) {
                        char val = m[r][c];
                        if (val == '.')
                            continue;

                        if (seen.count(val))
                            return false;

                        seen.insert(val);
                    }
                }
            }
        }

        return true;
    }
};

/**************************************************************************************/
/*
    Solution Approach:- Using HashMap and HashSet (Optimized)

    Time Complexity: O(1)
    Space Complexity: O(1)
    Since, the board size is fixed (9x9).

    Explanation:
        * Using three HashMaps to store the rows, columns, and 3x3 sub-boxes.
        * Using HashSet to check for duplicates in rows, columns, and 3x3 sub-boxes.
        * Iterate through each cell in the board and
            check for duplicates in respective row, column, and box,
            if found return false.
        * If no duplicates found, insert the value into respective row, column, and box.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, boxes;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.')
                    continue;

                int b = (r / 3) * 3 + c / 3;

                if (rows[r].count(ch) || cols[c].count(ch) ||boxes[b].count(ch))
                    return false;

                rows[r].insert(ch);
                cols[c].insert(ch);
                boxes[b].insert(ch);
            }
        }
        return true;
    }
};
