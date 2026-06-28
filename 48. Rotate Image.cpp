/*
    https://leetcode.com/problems/rotate-image
*/
/*
    Solution Approach:- Transpose the matrix and then reverse each row

    Time Complexity: O(N^2)
    Space Complexity: O(1)
    N = number of rows or columns in the matrix

    Explanation:-
        * We have to rotate the matrix by 90 degrees clockwise.
        * To achieve this, we can first transpose the matrix and then reverse each row.
        * Transposing the matrix means converting rows to columns and columns to rows.
        * Reversing each row means reversing the order of elements in each row.

    Ex:-
                            [
                                [1, 2, 3],
        input matrix =          [4, 5, 6],
                                [7, 8, 9]
                            ]

                            [
                                [1, 4, 7],
        traspose matrix =       [2, 5, 8],
                                [3, 6, 9]
                            ]

                            [
                                [7, 4, 1],
        input matrix =          [8, 5, 2],
                                [9, 6, 3]
                            ]
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int row = 0; row < n; row++)
            for (int col = row; col < n; col++)
                swap(matrix[row][col], matrix[col][row]);

        for (int row = 0; row < n; row++)
            reverse(matrix[row].begin(), matrix[row].end());
    }
};

/******************************************************************************************/
/*
    Solution Approach:- Rotate the matrix layer by layer

    Time Complexity: O(N^2)
    Space Complexity: O(1)
    N = number of rows or columns in the matrix

    Explanation:-
        * To achieve this, we can rotate the matrix layer by layer.
        * Each layer can be rotated by moving the elements in a circular manner.
        * We can use two pointers, left and right, to keep track of the current layer.
        * We can then iterate through the elements in the current layer and
            move them to their new positions.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size() - 1;

        while(left < right){
            for (int i = 0; i < (right - left); i++) {
                int top = left, bottom = right;

                int temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }

            left++;
            right--;
        }
    }
};
