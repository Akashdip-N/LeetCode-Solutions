/*
    https://leetcode.com/problems/merge-intervals
*/
/*
    Breif explanation:
        Given interval = [[1,3],[2,6],[8,10],[15,18]]
        Return the merged intervals = [[1,6],[8,10],[15,18]]

        Let's take the first two intervals [1,3] and [2,6].
        - Since the start time of the second interval (2)
            is less than or equal to the end time of the first interval (3),
                and the end time of the second interval (6) is
                    greater than the end time of the first interval (3),
                        so we merge them into [1,6].
*/
/*
    Solution Approach:- Using Sorting and Merging Intervals

    Time Complexity: O(N log N)
    Space Complexity: O(N)

    N = number of intervals

    Explanation:
        - First, we sort the intervals based on their starting times.
        - For each interval, we check
            if the current interval end time is
                greater than or equal to the next interval's start time.
            - If they overlap, we update the end time of the current interval,
                with the maximum of the two end times.
            - If they do not overlap, we push the current interval to the result
                and move to the next interval.
        - Finally, we push the last interval to the result.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        if(intervals.empty()) return merged;

        sort(intervals.begin(), intervals.end());
        vector<int> currentInterval = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {
            if(currentInterval[1] >= intervals[i][0])
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            else {
                merged.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }

        merged.push_back(currentInterval);
        return merged;
    }
};
