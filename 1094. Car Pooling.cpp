/*
    https://leetcode.com/problems/car-pooling/
*/
/*
    Solution Approach:- Using fixed size array

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = number of trips

    Intuition:-
        - We have been a list of trips, which has the following information for each trip:
            * Number of passengers
            * Start location
            * End location
        - Also have been given the capacity of the vehicle.
        - We have to check if it's possible for this vehicle,
            to pick up and drop off all the passengers for all the trips.

        - To solve this problem, we have been given that there are at most 1000 stops,
            so we would use a fixed size array of size 1001,
                to keep track of the number of passengers at each stop.
        - At the end we would return whether it would be possible
            for the vehicle to complete all the trips without exceeding the capacity at any stop.

    Explanation:-
        * Creating a fixed size array of size 1001, and intitalizing it with 0.
        * For each trip, performing the following operations:
            - Adding the number of passengers at the start location.
            - Subtracting the number of passengers at the end location.
        * After processing all the trips, we would iterate through the fixed size array,
            and for each stop, we would add the passengers for that stop
                and check if the current number of passengers exceeds the capacity.
            - If it does, we would return false.
            - Else we continue to the next stop.
        * If we exit out the loop that means the vehicle was able to complete all the trips
            without exceeding the capacity at any stop, so we would return true.
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001, 0);

        for (const auto& trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            stops[start] += passengers;
            stops[end] -= passengers;
        }

        int currentPassengers = 0;
        for (int i = 0; i <= 1000; i++) {
            currentPassengers += stops[i];

            if (currentPassengers > capacity)
                return false;
        }

        return true;
    }
};

/**********************************************************************************************/
/*
    Solution Approach:- Using Priority Queue

    Time Complexity:- O(NlogN)
    Space Complexity:- O(N)
    N = total number of trips

    Intuition:-
        - Same as the previous approach.
        - Instead using a priority queue, to keep track of the passenger count at each stop.
        - If we reach at the end that means the vehicle was able to complete all the trips
            without exceeding the capacity at any stop, so we would return true.

    Explanation:-
        * Using a lambda function to sort the trips based on the start location.
        * Using a priority queue to keep track of the
            end location as well as the number of passengers for each trip.
        * Iterating over each trip, and performing the following operations:-
            - Checking if the priority queue is empty or not, and
            - If the last trip's end location is less than the current trip's start location,
                that means we have completed the last trip from the priority queue,
                * Then, we decrease the number of passenger from the old trip in
                    the current passenger count.
                * Then we pop the last trip from the priority queue.
                * We keep on doing this till the last trip's end location is greater than
                    the current trip's start location.
            - Then we add the current trip's passenger count to the current passenger count.
            - If the current passenger count exceeds the capacity, we return false.
            - Else we push the current trip's end location and passenger count into the priority queue.
        * If we reach at the end that means the vehicle was able to complete all the trips
            without exceeding the capacity at any stop, so we would return true.
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >pq;

        int curPassenger = 0;

        for(auto trip : trips){
            int passenger = trip[0];
            int start = trip[1];
            int end = trip[2];

            while(!pq.empty() && pq.top().first <= start){
                curPassenger -= pq.top().second;
                pq.pop();
            }

            curPassenger += passenger;
            if(curPassenger > capacity)
                return false;

            pq.push({end, passenger});
        }


        return true;
    }
};
