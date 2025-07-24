/*
    https://leetcode.com/problems/spiral-matrix
*/
/*
    Solution Approach:

    Time Complexity: O(m * n)
    Space Complexity: O(1)

    m = number of rows
    n = number of columns in the matrix

    Explanation:
        - We maintain four boundaries: left, right, top, and bottom.
        - We traverse the matrix in a spiral order by moving
            right, down, left, and up in a loop until all elements are visited.
        - After each complete loop, we adjust the boundaries accordingly.
        - To handle the edge cases where the matrix has only one row or one column left,
            we check the boundaries before traversing in each direction.
        - The process continues until all elements are added to the result vector.
        - Finally, we return the result vector containing the elements in spiral order.
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

            // edge case check for single row remaining
            if(top <= bottom){
                for(int i = right; i >= left; i--)
                    ret.push_back(matrix[bottom][i]);
                bottom--;
            }

            // edge case check for single column remaining
            if(left <= right){
                for(int i = bottom; i >= top; i--)
                    ret.push_back(matrix[i][left]);
                left++;
            }
        }

        return ret;
    }
};
