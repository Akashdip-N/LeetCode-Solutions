/*
    https://leetcode.com/problems/pascals-triangle-ii/
*/
/*
    Solution Approach:- Using Dynamic Programming (Top-Down Approach)

    Time Complexity: O(N^2)
    Space Complexity: O(N)
    N = rowIndex

    Intuition:-
        - We are given a row number and we have to return the nth row of Pascal's triangle.

        - For each current and the next row element, adding the element of the previous row.
            Ex:-
                                index of each element       Row number
                1                      0                        0
               1 1                   0   1                      1
              1 2 1                0   1   2                    2
             1 3 3 1              0  1   2   3                  3

            So we can see that the
                element at index j of the current row is equal to the sum of
                    the elements at index j and j-1 of the previous row.

            row[3] element [2] => row[2] element [1] (1) + row[2] element [2] (2) => 3

    Explanation:-
        * Initializing the first row of Pascal's triangle as [1].
        * Iterating from 0 till rowIndex - 1, and for the each iteration,
            performing the following steps:-
            i.  Initializing the next row with size of current row + 1 and filling it with 0's.
            ii. Iterating through from 0 till the size of the last row,
                and for each iteration performing the following steps:-
                    a. For the current index, adding and storing
                        the value of the previous row's current index element,
                            into the current row's current index element.
                    b. For the next index, adding and storing
                        the value of the previous row's current index element,
                            into the current row's next index element.
            iii. Updating the current row with the next row.
        * At the end of the iterations, returning the current row as the result.
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};

        for(int i = 0; i < rowIndex; i++){
            vector<int> next_row(row.size() + 1, 0);

            for(int j = 0; j < row.size(); j++){
                next_row[j] += row[j];
                next_row[j+1] += row[j];
            }

            row = next_row;
        }

        return row;
    }
};
