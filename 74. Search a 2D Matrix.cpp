/*
    https://leetcode.com/problems/search-a-2d-matrix/
*/
/*
    Solution Approach:- Binary Search

    Time Complexity: O(log(M * N))
    Space Complexity: O(1)
    M = number of rows
    N = number of columns

    Explanation:-
        * Treating the 2D matrix as a 1D array and performing a binary search on it.
        * Using the formula to convert the 1D index to 2D indices.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int num_rows = matrix.size();
        int num_cols = matrix[0].size();

        // Row pointers
        int top = 0, bottom = num_rows - 1;

        while (top <= bottom) {
            int mid_row = top + (bottom - top) / 2;

            if(
                (matrix[mid_row][0] <= target)
                &&
                (target <= matrix[mid_row][num_cols - 1])
            ){
                int left = 0, right = num_cols - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    int cur = matrix[mid_row][mid];

                    if (cur == target)
                        return true;

                    if (cur < target)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }

                return false;
            }
            else if (target < matrix[mid_row][0])
                bottom = mid_row - 1;
            else
                top = mid_row + 1;
        }

        return false;
    }
};

/************************************* OWN SOLUTION :) *************************************/
/*
    Solution Approach:- Binary Search

    Time Complexity: O(M * log(N))
    Space Complexity: O(1)
    M = number of rows
    N = number of columns

    Explanation:-
        * Iterating through each row in the matrix,
            and checking if the target is within the range of the elements present in that row.
        * If it's present, performing a binary search on that row to find the target.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
        if (matrix.empty() || matrix[0].empty())
            return false;

        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0; i < row; i++){
            int min = matrix[i][0];
            int max = matrix[i][col-1];

            if((min <= target) && (target <= max)){
                int left = 0, right = col - 1;

                while(left <= right){
                    int mid = (left + right)/2;
                    int cur = matrix[i][mid];

                    if(cur == target)
                        return true;

                    if(cur < target)
                        left = mid + 1;
                    else
                        right = mid - 1;

                }
            }
        }

        return false;
    }
};
