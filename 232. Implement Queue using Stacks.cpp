/*
    https://leetcode.com/problems/implement-queue-using-stacks
*/
/*
    Solution Approach:- Using two stacks

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of elements in the queue

    Explanation:
        - Using two stacks, we can simulate the behavior of a queue.
        - The first stack (s1) is used to push elements.
        - The second stack (s2) is used to pop elements in the correct order.
        - When popping an element, if s2 is empty, we transfer all elements from
            stack (s1) to stack (s2) to reverse their order.
        - The peek operation checks the top of s2, transferring elements if necessary.
        - The empty operation checks if both stacks are empty.
*/
class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int x = peek();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty())
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
