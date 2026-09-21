/*
    https://leetcode.com/problems/single-element-in-a-sorted-array/
*/
/*
    Solution Approach:- Using Binary Search

    Time Complexity: O(logN) (Problem constraints)
    Space Complexity: O(1)
    N = size of the input array

    Intuition:-
        - Given us a sorted integer array where every element appears twice
            except for one element which appears only once.
        - We have to find the single element that appears only once in the array.
        - Constraints are we have to solve the problem in O(logN) time complexity
            and O(1) space complexity.

        - Since, given array is sorted and the time complexity should be O(logN),
            using binary search is the best approach to solve this problem.
        - But in this case we are measuring the size of the left side of the array
            to determine which side of the array have the single element.
        - If we can find we return the element, else we return -1 at the end.

    Explanation:-
        * Initalizing the left pointer to 0 and right pointer to size - 1.
        * While the left pointer is less than or equal to the right pointer,
            we perform the following steps:
            - Find the mid position of the array using left and right pointers.
            - Then check if the element to the left of the mid element is
                different from the mid element,
                    and also the value of (mid - 1) is greater than or equal to 0.
            - Then check if the element to the right of the mid element is
                different from the mid element,
                    and also the value of (mid + 1) is less than or equal to size - 1.
            - If both the left and right elements are different from the mid element,
                we return the mid element as the single element in the array.

            - Else, we find the size of the left sub-half of the array.
            - If we have even number of elements in the left sub-half of the array,
                we move the left pointer to mid + 1.
            - Else, we move the right pointer to mid - 1.
            (
                Since, it's given that each element appears twice,
                that means the side which is having the unique element
                will have odd number of elements in it.
            )

        * If we do not find the single element in the array, we return -1 at the end.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            bool left_different = (mid - 1 < 0) || (nums[mid - 1] != nums[mid]);
            bool right_different = (mid + 1 >= nums.size()) || (nums[mid + 1] != nums[mid]);

            if (left_different && right_different)
                return nums[mid];

            int leftsize = (mid > 0 && nums[mid - 1] == nums[mid]) ? mid - 1 : mid;

            if(leftsize % 2)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};
