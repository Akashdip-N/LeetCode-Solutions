/*
    https://leetcode.com/problems/trapping-rain-water
*/
/*
    Solution Approach: Two Pointer Approach

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = size of the height array

    Explanation:
        - Use two pointers, one starting from the left and one from the right.
        - Run a loop until the two pointers meet.
        - Check if the left maximum height is less than the right maximum height,
            because we are traversing from the left to the right,
                and if the height at the left pointer is less than the left maximum,
                    that means we can trap water at that position.
            - If so, increment the left pointer
                and check if the height at the left pointer is
                    less than the left maximum,
                        if so, add the difference to the water trapped.
                    else, update the left maximum.
        - Else,
            - Decrement the right pointer
                and check if the height at the right pointer is
                    less than the right maximum,
                        if so, add the difference to the water trapped.
                    else, update the right maximum.
        - Return the total water trapped.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int waterTrapped = 0;
        int l = 0, r = n - 1;
        int leftMax = height[l], rightMax = height[r];

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                if (height[l] < leftMax)
                    waterTrapped += leftMax - height[l];
                else
                    leftMax = height[l];
            } else {
                r--;
                if (height[r] < rightMax)
                    waterTrapped += rightMax - height[r];
                else
                    rightMax = height[r];
            }
        }
        return waterTrapped;
    }
};

/*******************************************************************************/
/*
    Solution Approach: Dynamic Programming

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = size of the height array

    Explanation:
        - Create two arrays, leftMax and rightMax, to store the maximum heights
            from the left and right sides respectively.
        - Traverse the height array from left to right to fill the leftMax array.
        - Traverse the height array from right to left to fill the rightMax array.
        - For each position in the height array, calculate the water trapped
            as the minimum of leftMax and rightMax minus the height at that position.
        - Sum up all the water trapped values and return it.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int waterTrapped = 0;
        vector<int> leftMax(n), rightMax(n);

        int maxLeft = height[0];
        for (int i = 0; i < n; i++) {
            leftMax[i] = maxLeft;
            maxLeft = max(maxLeft, height[i]);
        }

        int maxRight = height[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            rightMax[i] = maxRight;
            maxRight = max(maxRight, height[i]);
        }

        for (int i = 0; i < n; i++) {
            int waterAtCurrent = min(leftMax[i], rightMax[i]) - height[i];

            if (waterAtCurrent > 0)
                waterTrapped += waterAtCurrent;
        }
        return waterTrapped;
    }
};
