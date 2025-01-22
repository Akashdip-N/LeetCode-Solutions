/*
    https://leetcode.com/problems/pascals-triangle/
*/
/*
    Solution:

    1. Initialize a 2D vector triangle with the first row as {1}.
    2. Iterate from 1 to numRows.
    3. Create a new vector row.
    4. Push 1 to the row.
    5. Iterate from 1 to prevRow.size() - 1.
    6. Push prevRow[j - 1] + prevRow[j] to the row.
    7. Push 1 to the row.
    8. Push the row to the triangle.
    9. Return the triangle.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> row;
            vector<int>& prevRow = triangle[i - 1];
            row.push_back(1);

            for (int j = 1; j < prevRow.size(); j++)
                row.push_back(prevRow[j - 1] + prevRow[j]);

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle;
    }
};
