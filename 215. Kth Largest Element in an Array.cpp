/*
    https://leetcode.com/problems/kth-largest-element-in-an-array
*/
/*
    Solution Approach: Using Priority Queue (Min Heap)

    * Storing the values in the heap,
        and checking if the size of the heap exceeds k,
            If it does, we pop the smallest element from the heap.
                because the question asks for the kth largest element.

    * Returning the top element of the heap as the kth largest element.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};
