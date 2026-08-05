/*
    https://leetcode.com/problems/k-closest-points-to-origin/
*/
/*
    Solution Approach:- Using Priority Queue (Max Heap)

    Time Complexity:- O(NlogK)
    Space Complexity:- O(K)
    N = number of points
    K = number of closest points to origin

    Intuition:-
        - Need to find the k closest points from the origin (0, 0) in a 2D plane.
        - We need to keep a track of the k closest points to the origin.
        - Using a max heap priority queue to store both
            the distance the coordinates of the points.

    Explanation:-
        * Iterating through each point in the points vector.
        * For each point calculating the distance using the formula:
            distance = sqrt(x^2 + y^2)
            (Not using the euclidean rule to avoid floating point issues)
        * Pushing the distance and the point into the max heap priority queue.
        * If the size of the priority queue exceeds k,
            we pop the top element from the queue.
        * At the end we will have k closest points in the priority queue.
        * Then we pop the elements from the priority queue and
            push them into the result vector.
        * Finally returning the result vector.
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int distSq = x * x + y * y;

            pq.push({distSq, point});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

/*********************************************************************************/
/*
    Solution Approach:- Using Priority Queue (Min Heap)

    Time Complexity:- O(N + NlogK)
    Space Complexity:- O(N)
    N = number of points
    K = number of closest points to origin

    Intuition:-
        - This time since we are using a min heap,
            the value in the top of the heap will be the minimum distance from the origin.
        - So we can pop the top element from the heap k times
            to get the k closest points to the origin.

    Explanation:-
        * Pushing distance and the coordinates of the points into the min heap priority queue.
        * Then popping the top element from the heap k times to
            get the k closest points to the origin.
        * Finally returning the result vector.
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        >pq;

        for(const auto& point : points){
            int x = point[0];
            int y = point[1];
            int distance = x * x + y * y;

            pq.push({distance, point});
        }

        vector<vector<int>> result;

        while(!pq.empty() && k > 0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};
