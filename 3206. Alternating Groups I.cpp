/*
    https://leetcode.com/problems/alternating-groups-i
*/
/*
    Solution Approach:- Using Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of colors

    Intuition:-
        * We have to find a pair such that the 1st and the 3rd color are the same,
            and the 2nd color is different from the 1st and the 3rd color.
        * Using sliding window approach, we can find the count of such pairs in the colors array.
        * Since the colors are positioned in a circular manner, the first and the last color,
            are considered to be adjacent to each other.
        * For this we have to iterate from the [1] position, till the [size + 2] position of the colors array.

    Explanation:
        * Starting from the 1 position of the colors array,
            we will check if the color before the current color is the same as the current color.
        * If it is the same, we will move the left pointer to the current position.
        * If the length of the window is greater than 3,
            that means our window size is greater than 3,
                we will move the left pointer to the right.
        * If the length of the window is equal to 3,
            we will increment the count of the pairs.
        * Finally, we will return the count of the pairs
 */
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int size = colors.size();
        int left = 0;
        int count = 0;

        for (int right = 1; right < size + 3 - 1; right++) {
            if(colors[right % size] == colors[(right - 1) % size])
                left = right;

            if((right - left + 1) > 3)
                left++;

            if((right - left + 1) == 3)
                count++;
        }

        return count;
    }
};
