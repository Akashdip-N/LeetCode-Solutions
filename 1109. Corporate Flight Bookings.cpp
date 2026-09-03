/*
    https://leetcode.com/problems/corporate-flight-bookings/
*/
/*
    Solution Approach:- Using Prefix Sum and Difference Array

    Time Complexity: O(N + M)
    Space Complexity: O(N)
    N = number of flights
    M = number of bookings

    Intuition:-
        - We have been given a list of array consisting of the following:-
            i. First flight number
            ii. Last flight number
            iii. Number of seats booked for the flights within
                the range of first and last flight number (inclusive).
        - We have to return the total number of seats booked for each flight.

        - Since we know that the booking are within the given range of first and last flight
            numbers, that means after the last flight number,
                the seats booked will be reduced by the number of seats
                    booked for the flights within the range.
        - By using this concept we are solving this problem.

    Explanation:-
        * Creating a vector of size n (number of flights) and initializing it with 0.
        * Iterating through each booking in the bookings array and
            performing the following steps:-
            - Adding the number of seats booked to the first flight number (index).
            - Subtracting the number of seats booked from the last flight number + 1 (index).
        * At the end we are iterating from the second flight number
            from the start till the last flight number
                and adding the number of seats booked
                    for the previous flight number to the current flight number.
        * Finally, we return the vector containing the total
            number of seats booked for each flight.
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n, 0);

        for (const auto& booking : bookings) {
            int first = booking[0] - 1;
            int last = booking[1];
            int seatsCount = booking[2];

            seats[first] += seatsCount;
            if (last < n)
                seats[last] -= seatsCount;
        }

        for (int i = 1; i < n; i++)
            seats[i] += seats[i - 1];

        return seats;
    }
};

/**************************************************************************************/
/*
    Solution Approach:- Brute Force Approach

    Time Complexity: O(N * M)
    Space Complexity: O(N)
    N = number of flights
    M = number of bookings

    Intuition:-
        - Same as above
        - But instead using brute force approach,
            and iterating through each flight number within the range of first and
                last flight number
                    and adding the number of seats booked to the current flight number.
        - At the end we return the vector containing the total
            number of seats booked for each flight.
*/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n, 0);

        for(auto booking : bookings){
            int startflight = booking[0];
            int endflight = booking[1];
            int seat = booking[2];

            for(int i = startflight - 1; i < endflight; i++)
                seats[i] += seat;
        }

        return seats;
    }
};
