/*
    https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
*/
/*
    Solution Approach:- Using difference between max element and each element

    Time Complexity: O(N)
    Space Complexity: O(1)

    Intuition:-
        - We have been given an integer array.
        - We have to make sure all the elements are equal.
        - Given in each iteration we can increment that specific element by 1.

        - So, first we find the biggest element in the array.
        - Then we add the differnce between the biggest element and each element in the array.
        - This will give us the minimum moves to make all the elements equal.
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = -1;
        for(int num : nums)
            maxEle = max(num, maxEle);

        int count = 0;
        for(int num : nums)
            count += (maxEle - num);

        return count;
    }
};
