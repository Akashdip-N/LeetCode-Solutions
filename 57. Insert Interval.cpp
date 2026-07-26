/*
    https://leetcode.com/problems/insert-interval
*/
/*
    Solution Approach:-

    Time Complexity: O(N)
    Space Complexity: min(O(N), O(n))

    N = number of intervals
    n = size of the new interval array after insertion

    Intuition:
        * Given a list of non-overlapping intervals sorted by their start time.
        * We need to insert a new interval into the list of intervals and merge if necessary.
        * There are three cases to consider:
            1. The new interval is completely before the current interval.
            2. The new interval is completely after the current interval.
            3. The new interval overlaps with the current interval.

    Explanation:
        - If the interval list is empty, and we have to insert a new interval,
            we can simply add the new interval to the result and return it.

        - Iterating through each of the intervals from the list of intervals,
            and checking the following:-
            1. If the new interval end time comes before the start of the current interval,
                that means we can add the new interval to the result,
                    and then add the rest of the intervals to the result and return it.
            2. If the new interval start time is greater than the end time of the current interval,
                that means we have to skip this interval and add it to the result.
            3. If the new interval overlaps with the current interval,
                that means we have to store the minimum of start time of the current interval
                    and the new interval.
                And the maximum of the end time of the current interval and the new interval.
        - After iterating through all the intervals,
            we can add the new interval to the result and return it.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int intervalCount = intervals.size();

        for(int i = 0; i < intervalCount; i++){
            if(newInterval[1] < intervals[i][0]){
                result.push_back(newInterval);

                for(int j = i; j < intervalCount; j++)
                    result.push_back(intervals[j]);

                return result;
            }
            else
                if(newInterval[0] > intervals[i][1])
                    result.push_back(intervals[i]);
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.push_back(newInterval);
        return result;
    }
};
