/*
    https://leetcode.com/problems/implement-queue-using-stacks/description/

    Explanation:-
    * We have constaraint that we can use only stack.
    * The time complexity of push is O(1) and pop is O(n) in worst case.

    What we are doing is:-
    * Pushing values to stack s1.
    * While popping, we are checking if stack s2 is empty or not,
        if and only if s2 is empty, we are pushing all the elements of s1 to s2.
    * For peek operation, we are checking trying to find the top element of s2.
    * For the empty case, if both the stacks are empty,
        then only we can say that the queue is empty,
            else there are elements in the queue.
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
