/*
    https://leetcode.com/problems/kth-largest-element-in-a-stream
*/
/*
    Solution Approach:- Using Priority Queue

    Time Complexity:- O(N logK)
    Space Complexity:- O(K)
    N = Number of elements in the stream
    K = Kth largest element

    Intuition:-
        - We have to implement the following:-
            1. KthLargest(int k, vector<int>& nums) -
                Initializes the object with the integer k and the stream of integers nums.
            2. int add(int val) -
                Appends the integer val to the stream and
                returns the element representing the kth largest element in the stream.

        - Using a min-heap (priority queue) to keep track of the k largest elements in the stream.

    Explanation:-
        * Creating a min-heap (priority queue) to store the k largest elements in the stream.
        * And creating a variable to store the size of the min-heap (priority queue).

        KthLargest Operation:-
            * Takes an integer k and a vector of integers nums as input.
            * Initializes the size of the min-heap (priority queue) to k.
            * Iterating through each elements in the vector and
                calling the add function and passing the element as an argument.

        Add Operation:-
            * Takes an integer val as input.
            * Firsr checking if the size of the min-heap (priority queue) is less than k,
                then we push the element into the min-heap (priority queue).
            * Else if the size of the min-heap (priority queue) is equal to k
                then first we check
                    if the top element in the priority queue is less than the top element
                If true, then we pop the top element from the min-heap (priority queue) and
                push the new element into the min-heap (priority queue).
            * Finally we return the top element of the min-heap (priority queue).
*/
class KthLargest {
    private:
        int max_size;
        priority_queue<int, vector<int>, greater<int>> pq;
    public:
        KthLargest(int k, vector<int>& nums) {
            max_size = k;
            for (int num : nums)
                add(num);
        }

        int add(int val) {
            if(pq.size() < max_size)
                pq.push(val);
            else if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }

            return pq.top();
        }
};
