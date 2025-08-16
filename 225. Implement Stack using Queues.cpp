/*
    https://leetcode.com/problems/implement-stack-using-queues
*/
/*
    Solution Approach:- Using two queues

    Time Comeplexity: O(n)
    Space Complexity: O(n)
    n = number of elements in the stack

    Explanation:
        - Using two queues, to simulate stack behavior.
        - When a new element is pushed into the stack,
            it should appear at the front of the queue,
                so we first push the new element into the second queue,
                    then we move all elements from the first queue to the second queue.
        - When popping an element, we simply pop from the first queue.
        - The top element can be accessed directly from the first queue.
        - The empty function checks if the first queue is empty.
*/
class MyStack {
    private:
        queue<int> q1;
        queue<int> q2;

    public:
        MyStack() {}

        void push(int x) {
            q2.push(x);

            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            swap(q1,q2);
        }

        int pop() {
            int x =  top();
            q1.pop();
                return x;
        }

        int top() {
            return q1.front();
        }

        bool empty() {
            return q1.empty();
        }
};
