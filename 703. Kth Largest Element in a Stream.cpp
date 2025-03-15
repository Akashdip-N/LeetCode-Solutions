/*
    https://leetcode.com/problems/kth-largest-element-in-a-stream
*/
/*
    Solution Approach:- Using Priority Queue in the form of Min Heap

    * While pushing the value into the heap,
        check if the current size of the heap exceeds the maximum size,
            because in the question it is mentioned that
                we need to find the kth largest element.
                    so we do not need more than k elements in the heap.

    * Check if the value of the top element in the heap is less than the
        value being pushed into the heap
            if so, which means that the value being pushed is
                greater than the kth largest element
                    but we don't want to do that
                        so we pop the value first then push the new value
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
            else
                if(val > pq.top()){
                    pq.pop();
                    pq.push(val);
                }
            return pq.top();
        }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
