/*
    https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/
/*
    Solution Approach:- Using Breadth-First Search (BFS)

    Time Complexity:- O(N^2)
    Space Complexity:- O(N)
    N = size of the input matrix grid

    Intuition:-
        - We have to find the shortest path in a binary matrix of size N x N.
        - The path starts from pos (0, 0) and ends at pos (N-1, N-1).
        - In this case 0 will the path and 1 will be the obstacle.
        - We would use BFS to find the shortest path.
        - Using queue to store the positions that have been visited.
        - To avoid using extra space,
            each time we visit a position we will mark it as 1 in the grid.
                This would also avoid infite loops in the case of cycles.
        - Each time we would push the next position in the queue,
            we would increment the length of the path.
        - At the end, if we reach the destination position (N-1, N-1),
            we would return the length of the path.

    Explanation:-
        Base case:- Checking the following conditions if they are true, then return -1.
            i. If the starting position (0, 0) is not 0.
            ii. If the destination position (N-1, N-1) is not 0

        * Creating a 2D vector and storing the 8 possible directions in it.
        * Creating a queue to store the positions of the path that have been visited.
        * Pushing the starting position (0, 0) in the queue and
            marking it as 1 in the grid.
        * Initializing the length of the path as 1.
        * While the queue is not empty performing the following option:-
            - Getting the current number of positions present in the queue,
                which we would need to process in this level.
            - While we have positions to process for this level,
                    performing the following options:-
                * Getting the current position from the front of the queue and popping it.
                (
                    i.e. the current visited position in the path.
                )
                * Checking if the current position is at the destination position (N-1, N-1),
                    then returning the current length of the path.
                * For the current position, iterating over the 8 possible directions and
                    checking if the next position is valid and not visited,
                        then marking it as 1 and pushing the position in the queue.
                * Decrementing the number of positions to process for this level.
            - Incrementing the length of the path.
        * If we exit out of the loop that means we were not able to reach
            the destination position (N-1, N-1), then returning -1.
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();

        if (grid[0][0] != 0 || grid[size - 1][size - 1] != 0)
            return -1;

        int directions[8][2] = {
            {-1,-1}, {-1,0}, {-1,1},
            { 0,-1},         { 0,1},
            { 1,-1}, { 1,0}, { 1,1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int length = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize > 0) {
                auto [r, c] = q.front();
                q.pop();

                if (r == size - 1 && c == size - 1)
                    return length;

                for (auto& direction : directions) {
                    int nr = r + direction[0];
                    int nc = c + direction[1];

                    if (nr >= 0 && nr < size && nc >= 0 && nc < size && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }

                levelSize--;
            }

            length++;
        }

        return -1;
    }
};
