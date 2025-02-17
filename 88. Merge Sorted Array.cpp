/*
    https://leetcode.com/problems/merge-sorted-array/
*/
/*
    Solution Approach:-

    * We will compare the last number of nums1 and nums2 and
        put the greater number at the end of nums1.
    * We will keep on doing this until we reach the start of nums1 or nums2.
    * If we reach the start of nums2, we will put
        all the remaining elements of nums1 at the start of nums1.
    * If we reach the start of nums1, we will put
        all the remaining elements of nums2 at the start of nums1.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};
