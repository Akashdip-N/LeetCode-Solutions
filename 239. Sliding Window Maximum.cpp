/*
    https://leetcode.com/problems/sliding-window-maximum/
*/
/****************************** MONOTONIC DECREASING DEQUE ******************************/
/*
    Solution Approach: Deque (Double-Ended Queue)

    Time Complexity: O(N)
    Space Complexity: O(K)
    N = size of the input array
    K = size of the sliding window

    Explanation:
        * Using a deque to store indices of array elements.
        * Maintaining the deque such that the elements are in decreasing order.
        * For each new element,
            removing elements from the back of the deque that are smaller
                than the current element.
            adding the current element's index to the back of the deque.
        * Removing the front element of the deque if it is out of the current window.
        * Once the first window is formed, adding the maximum (front of the deque)
            to the result for each subsequent window.
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        int l = 0, r = 0;

        while(r < nums.size()) {
            while(!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();

            dq.push_back(r);

            if (l > dq.front())
                dq.pop_front();

            // Execute once we have the first full window
            if (r + 1 >= k) {
                res.push_back(nums[dq.front()]);
                l++;
            }

            r++;
        }

        return res;
    }
};
