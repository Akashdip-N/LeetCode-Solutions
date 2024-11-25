/*
    https://leetcode.com/problems/implement-stack-using-queues/description/

    Explanation:-
    * We have constaraint that we can use only stack.
    * The time complexity of push is O(1) and pop is O(n) in worst case.

    What we are doing is:-
    * Pushing values to queue q1.
    * Since, our main queue is q1,
        we will check if q1 is empty, then we will push the value to q1.
    * Making sure, both the queses are the same by using the swap() function.
    * For the pop operation, we will pop the front element from q1.
    * For the top operation, we will return the front element from q1.
    * Empty operation will return true if q1 is empty.
*/
class MyStack {
private:
    queue<int >q1;
    queue<int >q2;
public:
    MyStack() {

    }

    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
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

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
