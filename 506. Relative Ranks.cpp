/*
    https://leetcode.com/problems/relative-ranks/
*/
/*
    Solution Approach:- Using Priority Queue, Vector

    Time Complexity: O(n log n),
        explanation:- pushing elements into the priority queue
            takes O(log n), and we are doing it n times, so O(n log n)
    Space Complexity: O(n)

    * Pushing the elements and their positions into the priority queue.
    * Using for loop to iterate over each position of the array,
        taking the top element's position from the priority queue,
            based on the position of the element in the array,
                storing the rank of the element in the array in the vector.
*/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({score[i], i});

        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = pq.top().second;
            pq.pop();

            switch (i) {
                case 0:
                    ans[idx] = "Gold Medal";
                    break;
                case 1:
                    ans[idx] = "Silver Medal";
                    break;
                case 2:
                    ans[idx] = "Bronze Medal";
                    break;
                default:
                    ans[idx] = to_string(i + 1);
                    break;
            }
        }

        return ans;
    }
};
