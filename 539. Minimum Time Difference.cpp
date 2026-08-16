/*
    https://leetcode.com/problems/minimum-time-difference/
*/
/*
    Solution Approach:- Using Sorting

    Time Complexity: O(N logN) (logN for sorting)
    Space Complexity: O(N)
    N = length of timePoints

    Intuition:-
        - We have to find the minimum difference between any two time points from the list of time.
        - We would first convert the time points and store them in the vector,
            so that we can sort them and
                it would be easier for us to find the difference from a sorted list of time points.
        - Finding the Wrap-Around Gap:
            Total minutes in a day = 24 * 60 = 1440 minutes.
        - The shortest gap between 23:59 (1439 min) and 00:00 (0 min) is 1 minute.
        - Then finding the diffrence using this formula:- 1440 - (maxTime - minTime)
            Ex:-
                timePoints = ["23:59", "00:00"]
                minutes = [1439, 0]
                After sorting:- minutes = [0, 1439]
                wrapAroundDiff = 1440 - (1439 - 0) = 1

    Explanation:-
        * Using a vector to store the time points in minutes.
        * Iterating through each time from the array of given time points,
            and converting the time into minutes and storing it in the vector.
        * Sorting the vector of time points in ascending order.
            Ex:-
                timePoints = ["23:59", "00:00"]
                minutes = [1439, 0]
                After sorting:- minutes = [0, 1439]
        * Initializing the minimum difference as INT_MAX.
        * Iterating from the 1st index till the last index of the minutes vector,
            and calculating the difference between the current and previous time point,
                and updating the minimum difference if the current difference is smaller.
        * At the end, finding the wrap-around difference,
            and updating the minimum difference if the wrap-around difference is smaller.
        * Finally, returning the minimum difference.
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        int size = minutes.size();

        for (int i = 1; i < size; i++){
            int diff = minutes[i] - minutes[i - 1];
            minDiff = min(minDiff, diff);
        }

        int wrapAroundDiff = 1440 - (minutes[size - 1] - minutes[0]);
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};
