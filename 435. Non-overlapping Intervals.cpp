/*
    https://leetcode.com/problems/non-overlapping-intervals
*/
/*
    Solution Approach:- Using Sorting and Greedy Algorithm

    Time Complexity: O(N log N)
    Space Complexity: O(1)
    N = number of intervals

    Explanation:
        - First, we sort the intervals based on their end times,
            this helps in minimizing the number of intervals we need to remove.
        - We then iterate through the sorted intervals,
            keeping track of the end time of the last added interval.
        - If the start time of the current interval is
            greater than or equal to the end time of the current interval,
                that means there is no overlap,
                    and we can safely add this interval.
        - If there is an overlap, we increment the count of intervals to remove,
            and we update the end time to the minimum of the two overlapping intervals.
        - Finally, we return the count of intervals that need to be removed.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 1 || size == 0) return 0;

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int end = intervals[0][1];

        for (int i = 1; i < size; i++) {
            int start = intervals[i][0];

            if (start >= end)
                end = intervals[i][1];
            else {
                count++;
                end = min(end, intervals[i][1]);
            }
        }

        return count;
    }
};
