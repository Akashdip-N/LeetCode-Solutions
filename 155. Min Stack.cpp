/*
    https://leetcode.com/problems/min-stack/
*/
/*
    Solution Approach:- Using Two Stacks

    Time Complexity: O(1)       # Code requirements
    Space Complexity: O(N)
    N = Number of elements in the stack

    Intuition:-
        - We have to implement a stack that supports the following operations in constant time:
            1. push(x) -- Push element x onto stack.
            2. pop() -- Removes the element on top of the stack.
            3. top() -- Get the top element.
            4. getMin() -- Retrieve the minimum element in the stack.

        - Using two stacks, to perform the above operations in constant time.
            1. One stack to store the actual data.
            2. Another stack to store the minimum elements.

    Explanation:
        * Creating two stacks, one for the actual data and another for the minimum elements.

        Push Operation:-
            * Base case if the minstack is empty, then we push the first element into the minstack.
            * Or if the new element is less than or equal to the top value of the minstack,
                then we push the new element into the minstack.
            * Then we push the element into the data stack.

        Pop Operation:-
            * First we check if the top value of the minStack and the data stack are the same,
                then we pop the top value of the minStack.
            * Then we pop the top value of the data stack.

        Top Operation:-
            * We return the top value of the data stack.

        GetMin Operation:-
            * We return the top value of the minStack.
*/
class MinStack {
    private:
        stack<int> data;
        stack<int> minStack;
public:
    MinStack() {}

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
