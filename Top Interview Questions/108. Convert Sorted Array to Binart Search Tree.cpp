/*
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

/****************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* addNode(vector<int> a, int left, int right){
        if(left > right)
            return nullptr;

        int mid = (left + right)/2;
        TreeNode * temp = new TreeNode(a[mid]);

        temp->left = addNode(a, left, mid - 1);
        temp->right = addNode(a, mid+1, right);

        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return addNode(nums, 0, nums.size() - 1);
    }
};