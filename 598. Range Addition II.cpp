/*
    https://leetcode.com/problems/range-addition-ii/
*/
/*
    Solution Approach:- Using Math

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = number of operations in the array (i.e. size of the ops array)

    Intuition:-
        - Given a matrix of size m x n, with all elements initialized to 0.
        - Given a list of operations,
            where each operation is represented as a pair of integers [a, b].
        - Each operation increments all elements in the submatrix defined
            by the top-left corner (0, 0) and the bottom-right corner (a, b).
        - At the end of all operations,
            we need to return the count of maximum integers in the matrix.
        - Instead of simulating the entire operations on the matrix,
            we can find the
                min between the row of the matrix or the row of the operation,
                and the min between the column of the matrix or the column of the operation.
        - The final result will be the product of the minimum row and minimum column.

    Explanation:-
        * Since we know that the part of the matrix that will be incremented will be the one
            present in the operations array.
        * Therefore, finding the minimum row and
            minimum column will give us the size of the submatrix
                that will be incremented the most number of times.
        * And the product of it would be the count of maximum integers in the matrix.

    Ex:-
        Input: m = 3, n = 3, ops = [[2,2],[3,3]]
        Output: 4
        Explanation:

        The matrix is:-
            0 0 0
            0 0 0
            0 0 0

        After operation [2,2]:
            1 1 0
            1 1 0
            0 0 0

        After operation [3,3]:
            2 2 1
            2 2 1
            1 1 1

        The maximum integer in the matrix is 2, and there are 4 occurrences of it.
        which is equal to the product of the minimum row and minimum column (2 * 2 = 4).
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minR = m;
        int minC = n;

        for (const auto& op : ops) {
            minR = min(minR, op[0]);
            minC = min(minC, op[1]);
        }

        return minR * minC;
    }
};
