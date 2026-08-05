/*
    https://leetcode.com/problems/single-threaded-cpu/
*/
/*
    Solution Approach:- Using Priority Quue + Custom Sorting

    Time Complexity:- O(NlogN)
    Space Complexity:- O(N)
    N = number of tasks

    Intuition:-
        - We need to process the tasks based on their sequence of arrival and processing time.
        - We need to keep track of the current time as well as
            the sequence of the tasks of the tasks that is being processed.
        - We need to process the tasks based on their arrival time and least processing time.
            i.e.
                tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
                so the sequence in which the tasks would be processed are as follows:
                    - Time 1, task 4 [7,2]
                    - Time 3, task 3 [7,4], least processing time(4) compared to tasks [10,12,5]
                    - Time 7, task 2 [7,5], least processing time(5) compared to tasks [10,12]
                    - Time 12, task 0 [7,10], least processing time(10) compared to tasks [12]
                So the final sequence of the tasks would be [4,3,2,0,1]
        - Using priority queue to keep track of the enqueue time as well as the processing time.

    Explanation:-
        * Using vector to store the taks with their enqueue time, processing time and index.
        * Sorting the tasks vector based on the processing time.
            - Tasks Vector (before sorting) = [[7,10,0],[7,12,1],[7,5,2],[7,4,3],[7,2,4]]
            - Tasks Vector (sorted) = [[7,2,4],[7,4,3],[7,5,2],[7,10,0],[7,12,1]]
            - Tasks vector (index) =  [    4,      3,     2,       0,       1]

        * Creating a variable currentTime to keep track of the current time,
            and a variable taskIdx to keep track of the index of the tasks vector.
        * Running a while loop till we have processed all the tasks,
                or there is no tasks present in the priority queue.
            (that means we have processed all the tasks or there is no task available to process)
        * We perform the following operations inside the while loop:
            - If the queue is empty and the current time is less than index of the tasks vector.
                (
                    that means we do not have any task present in the queue to process,
                    and we are running the loop for the first time,
                    so we need to update the current time with the enqueue time of the task.
                )
                - Then we update the current time with the new task's enqueue time.
            - Then we check till which task,
                the enqueue time is less than the current time,
                    then we push the following into the priority queue:
                        - processing time
                        - index of the task
            - Also increment the taskIdx to keep track of the index of the tasks vector.

            - Then we fetch the latest task from the priority queue,
                and pop it from the queue.
            - Then we update the current time with the processing time of the task.
            - Then we push the index of the task into the result vector.
        * At the end we return the result vector,
            that consists of the sequence of the
                index of the tasks in the order they were processed.
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>> sortedTasks(n);
        for (int i = 0; i < n; ++i)
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};

        sort(sortedTasks.begin(), sortedTasks.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >pq;

        vector<int> result;
        long long currentTime = 0;
        int taskIdx = 0;

        while (taskIdx < n || !pq.empty()) {
            if (pq.empty() && currentTime < sortedTasks[taskIdx][0])
                currentTime = sortedTasks[taskIdx][0];

            while (taskIdx < n && sortedTasks[taskIdx][0] <= currentTime) {
                pq.push({sortedTasks[taskIdx][1], sortedTasks[taskIdx][2]});
                taskIdx++;
            }

            auto [processingTime, index] = pq.top();
            pq.pop();

            currentTime += processingTime;
            result.push_back(index);
        }

        return result;
    }
};
