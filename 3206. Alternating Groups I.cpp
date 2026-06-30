/*
    https://leetcode.com/problems/alternating-groups-i
*/
/*
    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of colors

    Explanation:
        i. Using two pointers to represent the sliding window.
        ii. Iterate through the colors array,
            checking if the current color is the same as the previous color,
                if they are the same, move the left pointer to the right.
        iv. If the size of the window is greater than k,
            move the left pointer to the right.
        v. If the size of the window is equal to k, increment the count.
        vi. Finally, return the count.
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
