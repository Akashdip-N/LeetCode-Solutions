/*
    https://leetcode.com/problems/balanced-binary-tree
*/
/*
    Solution Approach: Recursive Method, DFS

    * Comparing and calculating the height of the left subtree and right subtree.
    * If the difference is greater than 1,
        which means that the number of branches is not balanced,
            which means the tree is not balanced,
                hence will return false.
    * At the end, if both left and right subtrees are balanced,
        which means the tree is balanced,
            hence will return true.
*/

class Solution {
public:
    int height(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(leftHeight - rightHeight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
