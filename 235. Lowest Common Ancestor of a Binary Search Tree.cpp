/*
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
*/
/*
    Solution Approach:- Iterative Search

    Time Complexity: O(H)
    Space Complexity: O(1)
    H = Height of the tree

    Explanation:-
        i. Start from the root node of the BST.
        ii. If the value of the p and q nodes are both
            less than the value of the root node,
                set the root to its left child.
        iii. If the value of the p and q nodes are both
            greater than the value of the root node,
                set the root to its right child.
        iv. If neither of the above conditions are true,
                return the root node.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;

        while(root) {
            if(p->val < root->val && q->val < root->val)
                root = root->left;
            else
                if(p->val > root->val && q->val > root->val)
                    root = root->right;
            else
                return root;
        }

        return nullptr;
    }
};

/************************************************************************************/
/*
    Solution Approach:- Recursive Search

    Time Complexity: O(H)
    Space Complexity: O(H)
    H = Height of the tree

    Explanation:-
        i. Base case if root is null return null.
        ii. If the value of the p and q nodes are both
            less than the value of the root node,
                then search in the left subtree.
        iii. If the value of the p and q nodes are both
            greater than the value of the root node,
                then search in the right subtree.
        iv. If neither of the above conditions are true,
                return the root node.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};
