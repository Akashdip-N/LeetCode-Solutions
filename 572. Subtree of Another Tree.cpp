/*
    https://leetcode.com/problems/subtree-of-another-tree/description/
*/
/*
    Solution Approach: Recursive Method, DFS

    Time Complexity:- O(N * M)
    Space Complexity:- O(H)
    N = Number of nodes in the main tree
    M = Number of nodes in the subtree
    H = Height of the main tree

    Explanation:
        1. Main Function:
            * First check if the subtree is null, if yes return true.
            * Then check if the main tree is null, if yes return false.
            * Then check if the two trees are same using the helper function sameTree.
            * If they are same, return true.
            * If not, recursively check the left and right subtrees of the main tree.

        2. Helper Function (sameTree):
            * If both nodes are null, return true.
            * If both nodes are not null and their values are equal,
                recursively check their left and right children.
            * If any of the above conditions fail, return false.
 */
class Solution {
public:
    bool sameTree(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2)
            return true;

        if(node1 && node2 && node1->val == node2->val)
            return(
                sameTree(node1->left, node2->left) &&
                sameTree(node1->right, node2->right)
            );

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base Case:- Subtree is null
        if(!subRoot) return true;

        // Base Case:- Main tree is null
        if(!root) return false;

        if(sameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
