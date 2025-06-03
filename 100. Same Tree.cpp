/*
    https://leetcode.com/problems/same-tree/description/
*/
/*
    Approach: Recursive Depth-First Search (DFS)

    Time Complexity: O(n),
        n = number of nodes in the tree
    Space Complexity: O(1),
        h = height of the tree

    Explanation:
        * First, check if both nodes are null, then return true.
        * If one of the nodes is null, return false.
        * Then at last, recursively check the left and right subtrees,
            and return the results.
*/

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: if both nodes are null, they are the same tree
        if (!p && !q)
            return true;

        // If one of the node is null, that means the trees are not the same
        if (!p || !q)
            return false;

        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
