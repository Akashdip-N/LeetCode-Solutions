/*
    https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
*/
/******************************* OWN SOLUTION *******************************/
/*
                        TIME COMPLEXITY IS NOT OPTIMAL

    Solution: Using a max heap to store the elements of the matrix.

    Time Complexity: O(n^2 * logn)
    Space Complexity: O(n^2)

    Explanation:
        - Push all elements of the matrix into a max heap.
        - Since, we need the k-th smallest element,
            that means we need to pop (size*size - k) elements from the max heap.
        - After popping the required number of elements,
            the top of the max heap will be the k-th smallest element.
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int size = matrix.size();

        if (k > (size*size))
            return -1;

        int count = 0;
        for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            pq.push(matrix[i][j]);

        int diff = size*size - k;

        while(diff != 0){
            pq.pop();
            diff--;
        }

        return pq.top();
    }
};

/******************************* OPTIMAL SOLUTION *******************************/
/*
    Solution: Using binary search to find the k-th smallest element.

    Time Complexity: O(n * log(max-min))
    Space Complexity: O(1)

    Explanation:
        - The matrix is sorted in ascending order both row-wise and column-wise.
        - We can use binary search on the range of values in the matrix.
        - For each mid value, count how many elements are less than or equal to mid.
        - Adjust the search range based on the count until we find the k-th smallest element.
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0, j = n - 1;

            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid)
                    --j;
                count += (j + 1);
            }

            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
