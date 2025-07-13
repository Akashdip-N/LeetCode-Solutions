/*
    https://leetcode.com/problems/kth-largest-element-in-an-array
*/
/*
    Solution Approach: Using Priority Queue (Min Heap)

    Time Complexity: O(n log k)
    Space Complexity: O(k)
    n = size of the input array, k = the kth largest element to find

    Explanation:
        - Using min heap to keep track of the k largest elements.
        - Pushing all the elements into the min heap,
            and if the size of the heap exceeds k, we pop the smallest element.
        - At the end, returing the top element of the min heap.
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

/**********************************************************************************/
/*
    Solution Approach: Using Sorting

    Time Complexity: O(n log n)
    Space Complexity: O(1)
    n = size of the input array

    Explanation:
        - Sorting the array in ascending order.
        - Returning the (n-k) th element of the sorted array.

    NOTE:- Since we have sorted the array that means,
            the largest element or the nth largest element will be last element,
                hence the (n-k) th element will be the kth largest element.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       return nums[nums.size()-k];
    }
};
