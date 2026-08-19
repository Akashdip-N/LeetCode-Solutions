/*
    https://leetcode.com/problems/container-with-most-water/
*/
/*
    Solution Approach:- Using Two Pointer Approach

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of the input array

    Intuition:-
        - We have to find the area with maximum water that can be contained between two lines.
        - We would start from both ends of the array and calulate the area formed by the two lines.
        - Each time we would check the and store the area of the current two lines,
            and the current maximum area.
        - Then we would move the pointer based on the height of the line.
        - At the end we would return the maximum area found.

    Explanation:
        * Initializing left to 0 and right to the last index of the array.
        * Initializing max_area to 0.
        * While left is less than right:
            - Calculating the area formed by the two lines at left and right.
            - Updating max_area if the current area is greater than max_area.
            - If the height of the line at left is less than the height of the line at right,
                - Incrementing left pointer to move to the next line.
            - Else, decrementing right pointer to move to the previous line.
            (
                This is done because we want to maximize the area,
                    and the area is limited by the shorter line.
            )
        * Returning max_area.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while(left < right){
            int area = (right-left) * min(height[left], height[right]);
            max_area = max(area, max_area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return max_area;
    }
};
