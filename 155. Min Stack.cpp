/*
    https://leetcode.com/problems/min-stack/
*/
/*
    Time Complexity: O(1)       # Code requirements
    Space Complexity: O(n)

    Solution Approach:

    * Using Two Stacks
    * Since, we there is no way to access the minimum value
        in the stack, we need to keep track of the minimum value
        present in the stack.
    * push() function, inserts the value into the stack,
        AND if there are no elements present in the minStack,
            or the value to be inserted is less than or
                equal to the top of minStack.
    * pop() function, removes a value from the stack,
        AND if the value to be popped is equal to the top of minStack,
            pop the top element from minStack.
    * top() function, returns the top element of the stack.
    * getMin() function, returns the minimum element of the stack,
        using the minStack.
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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
