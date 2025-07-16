/*
    https://leetcode.com/problems/rotate-array/description/
*/
/*
    Solution Approach: Using reverse

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the array

    Explanation:
        - The idea is to reverse the entire array, then reverse the first k elements,
            and finally reverse the remaining n-k elements.
        - This effectively rotates the array to the right by k positions.
*/
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        k %= arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }
};

/**********************************************************************************/
/*
    Solution Approach: Using extra space

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = size of the array

    Explanation:
        - The idea is to create a temporary array to store the last k elements,
            then shift the remaining elements to the right.
        - Finally, copy the temporary array back to the original array.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        if (k == 0) return;

        vector<int> temp;

        for (int i = n - k; i < n; i++)
            temp.push_back(nums[i]);

        for (int i = n - 1; i >= k; i--)
            nums[i] = nums[i - k];

        for (int i = 0; i < k; i++)
            nums[i] = temp[i];
    }
};

/**********************************************************************************/
/*

    ----------------------- Time complexity not good at all. -----------------------

    Solution Approach: Using rotation

    Time Complexity: O(n*k)
    Space Complexity: O(1)
    n = size of the array
    k = number of rotations

    Explanation:
        - The idea is to rotate the array k times to the right.
        - For each rotation, we take the last element and move it to the front,
            shifting all other elements one position to the right.
        - This is done in a nested loop where the outer loop runs k times
            and the inner loop shifts elements in the array.
*/
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;

        if (k == 0) return;

        for(int i = 0; i < k; i++) {
            int temp = arr[n - 1];
            for(int j = n - 1; j > 0; j--)
                arr[j] = arr[j - 1];

            arr[0] = temp;
        }
    }
};
