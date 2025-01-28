/*
    https://leetcode.com/problems/container-with-most-water/
*/
/*
    Problem:- We have to find the maximum area of the container formed
        by the vertical lines of the given heights.

    Explantion:-
    * We are taking two pointers, left and right.
    * We are calculating the area between the two pointers.
    * We are updating the max_area with the maximum of the current area and the max_area.
    * We are moving the pointer which has the smaller height.
    * We are returning the max_area.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
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
