/*
    https://leetcode.com/problems/min-stack/
*/
/*
    Solution Approach:- Using Two Stacks

    Time Complexity: O(1)       # Code requirements
    Space Complexity: O(N)
    N = Number of elements in the stack

    Explanation:
        * We use two stacks,
            one to store the actual data and
                another to store the minimum elements.
        * When pushing an element,
            we check if it's smaller than or equal to the current minimum (top of minStack).
                If yes, we push it onto minStack as well.
        * When popping an element,
            we check if it's equal to the current minimum.
                If yes, we pop it from minStack as well.
        * The top() function returns the top element of the data stack.
        * The getMin() function returns the top element of the minStack,
            which is the minimum element in the data stack.
*/
class MinStack {
    private:
        stack<int> data;
        stack<int> minStack;
public:
    MinStack() {
        data = stack<int>();
        minStack = stack<int>();
    }

    void push(int val) {
        if(minStack.empty() || val <= minStack.top())
            minStack.push(val);
        data.push(val);
    }

    void pop() {
        if(data.top() == minStack.top())
            minStack.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minStack.top();
    }
};
