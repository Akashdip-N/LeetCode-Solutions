/*
    https://leetcode.com/problems/spiral-matrix
*/
/*
    Solution Approach:

    Time Complexity: O(M * N)
    Space Complexity: O(M * N)
    M = number of rows in the matrix
    N = number of columns in the matrix

    Intuition:-
        - Traversing the whole matrix from the outermost layer to the innermost layer in a spiral order.
        - With each complete loop, we adjust the boundaries of the matrix to move inward.

    Explanation:
        * Defining the 4 boundaries and assigning the respecitive values to them.
            - left = 0, right = matrix[0].size() - 1
            - top = 0, bottom = matrix.size() - 1
        * While the left side is less than or equal to the right side and
                the top side is less than or equal to the bottom side,
            - First we traverse from left to right side of the matrix and increment the top boundary.
            - Then we traverse from top to bottom side of the matrix and decrement the right boundary.
            - Then we traverse from right to left side (if we have some rows left) of the matrix
                and decrement the bottom boundary.
            - Then we traverse from bottom to top side (if we have some columns left) of the matrix
                and increment the left boundary.
        * Finally we return the resultant vector.
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;

        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;

        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++)
                ret.push_back(matrix[top][i]);
            top++;

            for(int i = top; i <= bottom; i++)
                ret.push_back(matrix[i][right]);
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--)
                    ret.push_back(matrix[bottom][i]);
                bottom--;
            }

            if(left <= right){
                for(int i = bottom; i >= top; i--)
                    ret.push_back(matrix[i][left]);
                left++;
            }
        }

        return ret;
    }
};
