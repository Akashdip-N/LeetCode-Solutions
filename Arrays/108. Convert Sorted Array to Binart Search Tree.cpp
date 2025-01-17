/*
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
/*
    The question asks for, balanced binary tree,
        which means both the right & left side of the node should have values in it.

    Ex:-
        nums = [-10,-3,0,5,9]

        The binary tree will be,

                    0
                   / \
                 -3   5
                 /   /
               -10  9

        The head is the mid element of the array, and
            the left and right child are the mid elements of the left and right
                subarray respectively.

    -----------------------------------------------------------------------------
    * Helper function to pass the values, the left and right index of the array.
    * Storing the left & right values of the array on the left & rightside of the mid element.
*/
class Solution {
public:
    TreeNode* addNode(vector<int> a, int left, int right){
        if(left > right)
            return nullptr;

        int mid = (left + right)/2;
        TreeNode * temp = new TreeNode(a[mid]);

        temp->left = addNode(a, left, mid - 1);
        temp->right = addNode(a, mid + 1, right);

        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return addNode(nums, 0, nums.size() - 1);
    }
};
