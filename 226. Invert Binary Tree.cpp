/*
    https://leetcode.com/problems/invert-binary-tree
*/
/*
    Solution Approach:- Recursive Approach

    * The question asks to make the left subtree of a node to be
        the right subtree of the same node and vice versa.

    Hence we recursively call the function and store
        the inverted left and right subtrees.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};
