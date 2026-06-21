/*
    https://leetcode.com/problems/sum-of-left-leaves
*/
/*
    Solution Approach: Recursive DFS
    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of nodes in the tree

    Explanation:
        - Asked to find the sum of all the left 'leaf' nodes in the tree.
        - A leaf node is a node that has no children (both left and right are null).
        - We will traverse the tree recursively, and for each node,
            we will check if it has a left child that is a leaf node.
        - If it does, we will add its value to the sum.
        - We will then continue to traverse the left and right subtrees recursively
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = 0;

        if (root->left != nullptr && !root->left->left && !root->left->right)
            sum += root->left->val;

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
