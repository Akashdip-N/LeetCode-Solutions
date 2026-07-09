/*
    https://leetcode.com/problems/daily-temperatures/
*/
/*
    Solution Approach:- Using Monotonic Stack

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = size of the input temperatures array

    Explanation:-
        * Using stack to store the indices of the temperatures array.
        * While iterating through the temperature array,
            * First we make sure that the stack is not empty,
                and the current temperature is greater than the temperature stored at the top of the stack.
            * If so, we pop the index from the stack and calculate the difference between the current
                index and the popped index to find the number of days until a warmer temperature,
                    we store this difference in the result array at the popped index.
        * Finally, we push the current index onto the stack.
        * After iterating through the entire temperature array, we return the result array.
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev_day_index = st.top();
                st.pop();

                res[prev_day_index] = i - prev_day_index;
            }

            st.push(i);
        }

        return res;
    }
};
