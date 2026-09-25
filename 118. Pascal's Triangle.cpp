/*
    https://leetcode.com/problems/pascals-triangle/
*/
/*
    Solution Approach:- Using Two Pointers

    Time Complexity:- O(N^2)
    Space Complexity:- O(N^2)
    N = numRows

    Intuition:-
        - Given number of rows, we need to generate Pascal's triangle.

        - Adding the number of the previous row's two adjacent numbers in the current row.

    Explanation:-
        * Creating a 2D vector to store the triangle.
        * Iterating from 0 till the number of rows, and performing the following steps:-
            i. Creating a vector of size i + 1 and initializing all the elements to 1.
            ii. Iterating from 1 till i, and
                storing the sum of the two adjacent numbers from the
                    previous row in the current row.
                (
                    We are starting from 1 because,
                        for the first two rows, we would only have 1's,
                            and we don't want to add the first and the last elements of the row.

                    Ex:-
                        Pascal's triangle for 5 rows would look like this:-
                            1
                           1 1
                          1 2 1     "Perform the addition operation from this row"
                         1 3 3 1

                )
            iii. Pushing the newly created row onto the triangle vector.
        * At the end, returning the triangle vector.
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];

            triangle.push_back(row);
        }

        return triangle;
    }
};
