/*
    https://leetcode.com/problems/longest-well-performing-interval/
*/
/*
    Solution Approach:- Using Prefix Sum and Monotonic Stack

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = size of the input array hours

    Problem statement:-
        - Given us an integer array hours representing the number of hours worked per day
            for a given employee.
        - If the number of hours worked in a day is greater than 8,
            then that day is considered a tiring day.
        - A well-performing interval is an interval of days for which
            (the number of tiring days) > (the number of non-tiring days).
        - Return the length of the longest well-performing interval.

    Intuition:-
        - Using prefix sum to store the difference between the number of tiring days and
            non-tiring days.
        - To calculate the prefix sum we are denoting tiring day by 1 and non-tiring day by -1.

        - Using stack to store the indices of the prefix sum array in decreasing order.
        - Finding the maxLen and returning it as the answer.

    Explanation:-
        * Storing the size of the input array hours in a variable size.
        * Creating a prefix sum array of size size + 1 and initializing it with 0.
        * Iterating through the input array hours and calculating the prefix sum.
            - If the number of hours worked in a day is greater than 8,
                then we add 1 to the prefix sum.
            - Otherwise, we subtract 1 from the prefix sum.

            Ex:-
                hours = [9, 9, 6, 0, 6, 6, 9]
                prefixSum = [0, 1, 2, 1, 0, -1, -2, -1]

        * Storing the indices of the prefix sum array in a stack in decreasing order.
            - If the stack is empty or
                the current prefix sum is less than the prefix sum at the top of the stack,
                    then we push the current index to the stack.
            Ex:-
                prefixSum = [0, 1, 2, 1, 0, -1, -2, -1]
                index =     [0, 1, 2, 3, 4,  5,  6,  7]
                stack = [0, 5, 6]

        * Iterating from the end of the prefix sum array till the begining of the array,
            to find the maximum length of the well-performing interval.
        Ex:-
            prefixSum = [0, 1, 2, 1, 0, -1, -2, -1]
            index =     [0, 1, 2, 3, 4,  5,  6,  7]
            stack = [0, 5, 6]
            maxLen = 0

            j = 7
                is prefixSum[7] (-1) > prefixSum[s.top() (6)] (-2)? Yes
                    maxLen = max(0, 7 - 6) = 1
                    stack = [0, 5]

                is prefixSum[7] (-1) > prefixSum[s.top() (5)] (-1)? No
                    maxLen = 1
                    stack = [0, 5]

            j = 6
                is prefixSum[6] (-2) > prefixSum[s.top() (5)] (-1)? No
                    maxLen = 1
                    stack = [0, 5]

            j = 5
                is prefixSum[5] (-1) > prefixSum[s.top() (5)] (-1)? No
                    maxLen = 1
                    stack = [0, 5]

            j = 4
                is prefixSum[4] (0) > prefixSum[s.top() (5)] (-1)? Yes
                    maxLen = max(1, 4 - 5) = 1
                    stack = [0]

                is prefixSum[4] (0) > prefixSum[s.top() (0)] (0)? No
                    maxLen = 1
                    stack = [0]

            j = 3
                is prefixSum[3] (1) > prefixSum[s.top() (0)] (0)? Yes
                    maxLen = max(1, 3 - 0) = 3
                    stack = []

            j = 2
                is prefixSum[2] (2) > prefixSum[s.top() (empty)]? Yes
                    maxLen = max(3, 2 - empty) = 3
                    stack = []
            j = 1
                is prefixSum[1] (1) > prefixSum[s.top() (empty)]? Yes
                    maxLen = max(3, 1 - empty) = 3
                    stack = []
            j = 0
                is prefixSum[0] (0) > prefixSum[s.top() (empty)]? Yes
                    maxLen = max(3, 0 - empty) = 3
                    stack = []
        * Returning the maxLen as the answer.
*/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int size = hours.size();
        vector<int> prefixSum(size + 1, 0);

        for (int i = 0; i < size; i++)
            prefixSum[i + 1] = prefixSum[i] + (hours[i] > 8 ? 1 : -1);

        stack<int> s;
        for (int i = 0; i <= size; i++){
            if (s.empty() || prefixSum[i] < prefixSum[s.top()])
                s.push(i);
        }

        int maxLen = 0;
        for (int j = size; j >= 0; j--) {
            while (!s.empty() && prefixSum[j] > prefixSum[s.top()]) {
                maxLen = max(maxLen, j - s.top());
                s.pop();
            }
        }

        return maxLen;
    }
};
