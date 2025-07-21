/*
    https://leetcode.com/problems/container-with-most-water/
*/
/*
    Problem:- Using two pointers.

    Time Complexity: O(n)
    Space Complexity: O(1)
    n = length of the input array

    Explanation:
        - We have to find the maximum area that can be formed
          between two lines represented by the heights in the array.
        - Using two pointers, `left` and `right`, to find the maximum area.
        - The area is calculated as the width between the two pointers
            multiplied by the minimum height of the two lines.
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
                left += 1;
            else
                right -= 1;
        }

        return max_area;
    }
};
