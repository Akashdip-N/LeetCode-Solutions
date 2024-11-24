/*
    https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

/*----------------------------------------------------------------*/
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
    void operation(TreeNode* root, vector<int> &a){
        if(!root)
            return;
        
        operation(root->left);
        a.push_back(root->val);
        operation(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        operation(root, a);
        return a;
    }
};