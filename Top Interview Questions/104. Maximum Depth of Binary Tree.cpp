/*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/
/*****************************************************************/

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
    int recursive_approach(TreeNode* root, int depth){
        if(root == NULL)
            return depth;
        return max(recursive_approach(root->left, depth+1),
                    recursive_approach(root->right, depth+1));
    }

    int maxDepth(TreeNode* root){
        int depth = 0;
        depth = recursive_approach(root, depth);
        return depth;
    }
};