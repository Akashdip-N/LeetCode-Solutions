/*
    https://leetcode.com/problems/insert-interval
*/
/*
    Solution Approach:-

    Time Complexity: O(N)
    Space Complexity: min(O(N), O(n))

    N = number of intervals
    n = size of the new interval array after insertion

    Explanation:
        - First we check if the intervals array is empty,
            if it is, we simply return the new interval as the result.
        - We iterate through the intervals and check:
            - If the new interval ends before the current interval starts,
                then we insert the new interval before the current interval
                    and add all remaining intervals to the result,
                        and return the result.
        - Else we check the new interval starts time is greater than
            the current interval ends time,
                then we simply add the current interval to the result.
        - If none of the above conditions are met,
            it means the new interval overlaps with the current interval.
            that means,
                we need to find the minimum start time and maximum end time
                    of the overlapping intervals and update the new interval.
        - Finally, we add the updated new interval to the result.
        - Return the result.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int intervalCount = intervals.size();

        if(intervalCount == 0) {
            result.push_back(newInterval);
            return result;
        }

        for(int i = 0; i < intervalCount; i++){
            if(newInterval[1] < intervals[i][0]){
                result.push_back(newInterval);

                for(int j = i; j < intervalCount; j++)
                    result.push_back(intervals[j]);

                return result;
            }
            else if(newInterval[0] > intervals[i][1]){
                result.push_back(intervals[i]);
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.push_back(newInterval);
        return result;
    }
};
