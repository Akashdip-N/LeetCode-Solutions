/*
    https://leetcode.com/problems/intersection-of-two-arrays/
*/
/*
    Solution Approach:- Using HashSet

    Time Complexity:- O(N + M)
    Space Complexity:- O(max(N, M)) (Either the Hashset of the result vector can have max space)
    N = size of nums1
    M = size of nums2

    Intuition:-
        - Given us two integer arrays nums1 and nums2.
        - We have to return the common elements in both the arrays.
        - The result should only contain unique elements and can be returned in any order.

        - We would use HashSet to store the elements of the first array.
        - Then we would iterate through the second array,
            and if the element is present in the hashset,
                then we would remove it from the hashset and add it to the result vector.
        - At the end we would return the result vector.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> result;

        for (int num : nums2)
            if (s.erase(num))
                result.push_back(num);

        return result;
    }
};
