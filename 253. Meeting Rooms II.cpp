/*
    https://leetcode.com/problems/meeting-rooms-ii/description/ (premium)
    https://neetcode.io/problems/meeting-schedule-ii/question
*/
/*
    Solution Approach: Using Priority Queue (Min Heap)

    Time Complexity: O(N * logN) (because of sorting)
    Space Complexity: O(N)
    N = number of intervals

    Intuition:-
        - Different time intervals are given,
            we need to find the intervals that do not operlap with the other interval.
        - Sorting the intervals based on the start time,
            so that we can easily find the overlapping intervals.
        - Using a min heap to keep track of the end time of the intervals,
            so that we can easily find the interval that ends the earliest.
        - The min heap would contain the number of end times of the intervals,
            thus showing the number of meeting rooms required.

    Explanation:-
        * Sorting the intervals based on the start time.
        * Storing the end time of the first interval in the min heap.
        * Iterating through the rest of the intervals,
            - If the start time of the current interval is
                greater than or equal to the end time,
                    that means the
                        current interval does not overlap with the previous interval,
                            so we pop the end time of the earlier interval from the min heap.
            - We push the end time of the current interval into the min heap.
        * Finally, the size of the min heap will be the number of meeting rooms required.
*/
class Solution {
    private:
        static bool compareIntervals(const Interval& a, const Interval& b) {
            return a.start < b.start;
        }

    public:
        int minMeetingRooms(vector<Interval>& intervals) {
            if (intervals.empty())
                return 0;

            sort(intervals.begin(), intervals.end(), compareIntervals);
            priority_queue<int, vector<int>, greater<int>> pq;

            pq.push(intervals[0].end);

            for (int i = 1; i < intervals.size(); i++) {
                if (intervals[i].start >= pq.top())
                    pq.pop();

                pq.push(intervals[i].end);
            }

            return pq.size();
        }
};
