/*
    https://leetcode.com/problems/container-with-most-water/
*/
/*
    Problem:- Using two pointers.

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:
        - Two pointers are initialized at the start and end of the array.
        - Run a loop until the two pointers meet.
        - First calculate the area formed by the two pointers.
        - Update the maximum area if the current area is larger.
        - Check if the
            left pointer's height is less than the right pointer's height,
                if so, increment the left pointer.
        - Else decrement the right pointer.
        - Return the maximum area found.
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
