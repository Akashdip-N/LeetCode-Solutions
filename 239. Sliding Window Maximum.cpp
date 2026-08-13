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


    Intuition:-
        - We have to find the max element in each sliding window of size k.
        - To maintain the max element for each window,
            using deque.
        - The deque will store the indices of the element
            in decresing order of their values.
        - The front of the deque will always have the index of the maximum element
            for the current window.

    Explanation:
        * Intializing left and right pointers to 0.
        * Iterating through the array using the right pointer.
        * If the current element is greater than the last element in the deque,
            we would pop the element from the back of the deque
                until we find an element greater than the current element.
        * Then we will add the current index to the back of the deque.
        * If the left pointer is greater than the front of the deque,
            we will remove the front element from the deque.

            This will only be true if all the elements after the front element
                are smaller than the current element,
                    and the front element is no longer in the current window.

        * Once we have the first full window (when right pointer is greater than or equal to k - 1)
            we will add the maximum element (nums[dq.front()]) to the result vector.
        * Finally, we will increment the left pointer and
            continue the process until we reach the end of the array.

    Ex:-
        Input:
            nums = [1,3,-1,-3,5,3,6,7]
            k = 3
        Output: [3,3,5,5,6,7]

        Iteration 1:
            l = 0, r = 0
            dq = [0]

        Iteration 2:
            l = 0, r = 1
            dq.back() = 0
            if nums[0] < nums[1] => 1 < 3 => true
            dq.pop_back() => dq = []
            dq.push_back(r) => dq = [1]

        Iteration 3:
            l = 0, r = 2
            dq.back() = 1
            if nums[1] < nums[2] => 3 < -1 => false
            dq.push_back(r) => dq = [1, 2]

            r + 1 >= k => 2 + 1 >= 3 => true
            res.push_back(nums[dq.front()]) => res = [3]

        Iteration 4:
            l = 1, r = 3
            dq.back() = 2
            if nums[2] < nums[3] => -1 < -3 => false
            dq.push_back(r) => dq = [1, 2, 3]

            l > dq.front() => 1 > 1 => false

            r + 1 >= k => 3 + 1 >= 3 => true
            res.push_back(nums[dq.front()]) => res = [3, 3]

        Iteration 5:
            l = 2, r = 4
            dq.back() = 3
            if nums[3] < nums[4] => -3 < 5 => true
            dq.pop_back() => dq = [1, 2]
            dq.back() = 2
            if nums[2] < nums[4] => -1 < 5 => true
            dq.pop_back() => dq = [1]
            dq.back() = 1
            if nums[1] < nums[4] => 3 < 5 => true
            dq.pop_back() => dq = []
            dq.push_back(r) => dq = [4]

            l > dq.front() => 2 > 4 => false

            r + 1 >= k => 4 + 1 >= 3 => true
            res.push_back(nums[dq.front()]) => res = [3, 3, 5]

        Iteration 6:
            l = 3, r = 5
            dq.back() = 4
            if nums[4] < nums[5] => 5 < 3 => false
            dq.push_back(r) => dq = [4, 5]

            l > dq.front() => 3 > 4 => false
            r + 1 >= k => 5 + 1 >= 3 => true
            res.push_back(nums[dq.front()]) => res = [3, 3, 5, 5]

        Iteration 7:
            l = 4, r = 6
            dq.back() = 5
            if nums[5] < nums[6] => 3 < 6 => true
            dq.pop_back() => dq = [4]
            dq.back() = 4
            if nums[4] < nums[6] => 5 < 6 => true
            dq.pop_back() => dq = []
            dq.push_back(r) => dq = [6]

            l > dq.front() => 4 > 6 => false
            r + 1 >= k => 6 + 1 >= 3 => true
            res.push_back(nums[dq.front()]) => res = [3, 3, 5, 5, 6]

        Iteration 8:
            l = 5, r = 7
            dq.back() = 6
            if nums[6] < nums[7] => 6 < 7 => true
            dq.pop_back() => dq = []
            dq.push_back(r) => dq = [7]

            l > dq.front() => 5 > 7 => false
            r + 1 >= k => 7 + 1 >= 3 => true
            res.push_back(nums[dq.front()]) => res = [3, 3, 5, 5, 6, 7]
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        int l = 0;

        for(int r = 0; r < nums.size(); r++) {
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
        }

        return res;
    }
};
