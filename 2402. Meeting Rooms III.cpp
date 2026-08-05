/*
    https://leetcode.com/problems/meeting-rooms-iii/
*/
/*
    Solution Approach:- Using Priority Queue

    Time Complexity:- O(MlogM + MlogN)
    Space Complexity:- O(N)
    M = number of meetings
    N = number of rooms

    Intuition:-
        - We have to keep track of two things,
            1. Which rooms are free and available for meetings.
            2. Which rooms are currently occupied and when they will be free.
        - That means we have to use two seperate priority queues (min-heap)
            i. one for free rooms
            ii. one for occupied rooms.
        - And we have to keep track of the number of meetings held in each room,
            for this we are using a vector of size number of rooms.
        - Also we have to keep track of the meeting duration,
            so that we can know when the room will be free after the meeting is over.

    Explanation:-
        * Sorting the meeting duration based on the start time.
        * Storing the number of meeting rooms from 0 to n-1 in the min-heap priority queue.
        * Iterating through each of the meeting intervals from the meetings array,
            and performing the following operations:-
            1. Store the start time, end time and duration of the meeting.
            2. Then check if the used room is empty or not and
                the last meeting's end time is less than or equal to the start time
                    of the current meeting,
                (
                    that means we have rooms that is present in the used room and
                    and the new meeting's start time comes after the last meeting's end time,
                    so we can use that room for the new meeting.
                )
                then pop the room from the used room pq and push it to the free room pq.
            3. Then check if there are rooms present that are free to be used in the free room pq,
                - if true then store the room number in a variable,
                    and pop the room from the free room pq and
                        push it to the used room pq with the end time of the current meeting,
                            and increment the count of meetings held in that room.
                - if false that means either this is the first meeting room or
                    all the rooms are occupied,
                        then we fetch the end time and the room number of the earliest occupied
                            room from the used room pq, and pop it from the used room pq and
                                push it back update the end time of the room
                                    with the duration of the current meeting,
                                and increment the count of meetings held in that room.
        * Then we iterate through the count vector and
            find the room with the maximum number of meetings held
        * Return the room number.
*/
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<
            int,
            vector<int>,
            greater<int>
        >freeRooms;
        for (int i = 0; i < n; i++)
            freeRooms.push(i);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        >usedRooms;

        vector<int> count(n, 0);

        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                freeRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }

            if(!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                usedRooms.push({end, room});
                count[room]++;
            } else {
                auto [earliestEnd, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({earliestEnd + duration, room});
                count[room]++;
            }
        }

        int maxBookedRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxBookedRoom])
                maxBookedRoom = i;
        }

        return maxBookedRoom;
    }
};
