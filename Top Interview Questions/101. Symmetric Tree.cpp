/*
    https://leetcode.com/problems/symmetric-tree/
*/

/*------------------------------------------------*/
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
    bool checkChildNodes(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL)
            return false;
        if(right == NULL)
            return false;
        if(left->val != right->val)
            return false;
        return checkChildNodes(left->left, right->right) && checkChildNodes(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return true;
        return checkChildNodes(root->left, root->right);
    }
};