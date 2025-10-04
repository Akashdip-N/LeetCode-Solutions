/*
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/
/*
    Solution Approach:- Two Pointer with Binary Search

    Time Complexity:- O(N)
    Space Complexity:- O(1)
    N = size of the input array

    Solution:-
        i. Initialize two pointers, left and right, to the start and end of the array.
        ii. While left is less than right:
            a. Calculate the sum of the elements at the left and right pointers.
            b. If the sum equals the target, return the indices (left + 1, right + 1).
            c. If the sum is less than the target,
                increment the left pointer to increase the sum.
            d. If the sum is greater than the target,
                decrement the right pointer to decrease the sum.
        iii. If no such pair is found, return an empty vector.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size()-1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return {left + 1, right + 1};
            else
                if(sum < target)
                    left += 1;
            else
                right -= 1;
        }
        return res;
    }
};
