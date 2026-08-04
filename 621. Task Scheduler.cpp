/*
    https://leetcode.com/problems/task-scheduler/
*/
/*
    Solution Approach:- Using Priority Queue + Deque + Hash Map

    Time Complexity: O(NlogN)
    Space Complexity: O(1) (Since at max 26 tasks possible)
    N = number of tasks

    Intuition:-
        * We have to keep a track on the tasks which are choosing at the moment.
        * Also we have to keep track on the cooling interval in between the same tasks.
        * Using hash map to keep track of the number of occurrences of each task
            to store it in the priority queue.
        * Using prirotity queue to keep the track of the tasks that
            present the most number of times.
        * Using deque to keep track of the tasks that are cooling down and
            when they can be used again.

    Explanation:-
        * Creating a hash map to store the number of occurrences of each task.
        * Pushing the occurrences of each task into a priority queue.
        * While the priority queue is not empty or the deque is not empty,
            we will keep track of the time.
                i.e. there are tasks that are present either
                    in the cooling period or
                    in the number of occurrences of the tasks is not 0
        * Performing the following operations in each iteration of the loop:-
            - Incrementing the time by 1 to keep a track of the current time we are in.
            - Checking if the priority queue is empty or not,
                that means there are no more elements present to be checked in
                    from the priority queue.
            - If it's emopty that means no more tasks present then
                poping the number of occurances of that task
                    and decrementing it by 1 to
                        keep track of the number of occurrences of that task.
            - If the number of occurrences of that task is greater than 0,
                that means we tasks still present in the priority queue and
                    we have to push it into the deque with the time when it can be used again.
            - Checking if the deque is empty or not,
                that means there are no more elements present to be checked in from the deque.
            - If it's not empty that means there are tasks present in the deque and
                we have to check if the time when it can be used again
                    is equal to the current time.
            - Then we push the number of occurances of that task
                back into the priority queue and pop it from the deque.
        * Finally returning the time which is the least number of intervals
            that the CPU will take to finish all the given tasks.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for (char task : tasks)
            m[task]++;

        priority_queue<int> pq;
        for (auto& [task, occurrence] : m)
            pq.push(occurrence);

        deque<pair<int, int>> dq;
        int time = 0;

        while (!pq.empty() || !dq.empty()) {
            time++;

            if (!pq.empty()) {
                int count = pq.top() - 1;
                pq.pop();

                if (count > 0)
                    dq.push_back({count, time + n});
            }

            if (!dq.empty() && dq.front().second == time) {
                pq.push(dq.front().first);
                dq.pop_front();
            }
        }

        return time;
    }
};
