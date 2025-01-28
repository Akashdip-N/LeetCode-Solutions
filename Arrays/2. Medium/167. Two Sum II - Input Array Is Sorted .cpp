/*
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/
/*
    Time Complexity:- O(n)
    Space Complexity:- O(1)

    -------------------------------------------------------------------------
    Ex:- numbers = [2,7,11,15], target = 9
    Output:- [1,2]

    Solution:-
    1. We are taking two pointers, left and right.
    2. Assigninining left = 0 and right = numbers.size()-1.
    3. Calculating the sum of the elements at the left and right pointers.
    4. If the sum is equal to the target,
        we are returning the indices of the elements.
    5. If the sum is less than the target,
        that means we need bigger elements,
            so we are incrementing the left pointer.
    6. If the sum is greater than the target,
        that means we need smaller elements,
            so we are decrementing the right pointer.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size()-1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                return {left+1, right+1};
            else
                if(sum < target)
                    left += 1;
            else
                right -= 1;
        }
        return res;
    }
};
