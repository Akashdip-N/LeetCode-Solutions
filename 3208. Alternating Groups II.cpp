/*
    https://leetcode.com/problems/alternating-groups-ii
*/
/*
    Solution Approach: Sliding Window

    Time Complexity: O(N)
    Space Complexity: O(1)
    N = length of colors

    Explanation:
        i. (THIS PROBLEM IS THE CONTINUTATION OF THE PREVIOUS PROBLEM "Alternating Groups I")
            https://leetcode.com/problems/alternating-groups-i
        ii. The only difference is that the size of the window is not fixed to 3,
            but it can be any value of k.
*/
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int size = colors.size();
        int left = 0;
        int count = 0;

        for (int right = 1; right < size + k - 1; right++) {
            if(colors[right % size] == colors[(right - 1) % size])
                left = right;

            if((right - left + 1) > k)
                left++;

            if((right - left + 1) == k)
                count++;
        }

        return count;
    }
};
