/*
    https://leetcode.com/problems/set-matrix-zeroes
*/
/*
    Solution Approach: Iterating twice through the matrix.

    Time Complexity: O(m * n)
    Space Complexity: O(1)
    m = number of rows in the matrix.
    n = number of columns in the matrix.

    Explanation:
         - First pass: Identify the rows and columns that need to be set to zero.
         - Second pass: Set the identified rows and columns to zero.
         - Handle the first row and first column separately
            to avoid overwriting them.
        - At the end, if the first row or first column needs to be set to zero,
            we handle that separately.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool rowZero = false;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++)
                if(matrix[row][col] == 0) {
                    matrix[0][col] = 0;

                    if(row > 0)
                        matrix[row][0] = 0;
                    else
                        rowZero = true;
                }
        }

        for(int row = 1; row < rows; row++)
            for(int col = 1; col < cols; col++)
                if(matrix[0][col] == 0 || matrix[row][0] == 0)
                    matrix[row][col] = 0;

        // If the first element of the matrix is zero
        if(matrix[0][0] == 0) {
            for(int row = 0; row < rows; row++)
                matrix[row][0] = 0;
        }

        // If the first row needs to be set to zero
        if(rowZero) {
            for(int col = 0; col < cols; col++)
                matrix[0][col] = 0;
        }
    }
};

/*************************************************************************************/
/*
    Solution Approach: Using Hash Map

    Time Complexity: O(m * n)
    Space Complexity: O(k)
    m = number of rows in the matrix.
    n = number of columns in the matrix.
    k = number of zeros in the matrix.

    Explanation:
        - Iterate through the matrix and store the positions of zeros in a map.
        - Iterate through the map and set the corresponding rows and columns to zero.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, vector<int>> mp;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 1;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++)
                if(matrix[row][col] == 0) {
                    mp[count] = {row, col};
                    count++;
                }
        }

        for(auto& it : mp) {
            int row = it.second[0];
            int col = it.second[1];

            for(int i = 0; i < rows; i++)
                if (matrix[i][col] != 0)
                    matrix[i][col] = 0;

            for(int j = 0; j < cols; j++)
                if (matrix[row][j] != 0)
                    matrix[row][j] = 0;
        }
    }
};
