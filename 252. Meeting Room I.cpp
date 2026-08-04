/*
	https://leetcode.com/problems/meeting-rooms/description/
*/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(NlogN)
    Space Complexity: O(1)
    N = number of intervals

    Intuition:-
        - If the start of the current interval,
            overlaps with the end of the previous interval,
                then we cannot attend all the meetings.
        - First we would sort the intervals based on the start time of the meetings.
        - Then would compare the times and return the result.

    Explanation:-
        * Sorting the intervals based on the start time of the meetings.
        * Iterating through each of the intervals and,
            checking if the start time of the current interval is
                less than the end time of the previous interval.
                    then return false
        * If we reach the end of the intervals without returning false,
            then we can attend all the meetings and return true.
*/
class Solution {
public:
    private:
        static bool compareIntervals(const Interval& a, const Interval& b) {
            return a.start < b.start;
        }

    public:
        bool canAttendMeetings(std::vector<Interval>& intervals) {
            sort(intervals.begin(), intervals.end(), compareIntervals);

            for(int i = 1; i < intervals.size(); i++)
                if(intervals[i - 1].end > intervals[i].start)
                    return false;

            return true;
        }
};
