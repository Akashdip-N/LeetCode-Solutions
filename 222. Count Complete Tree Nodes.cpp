/*
    https://leetcode.com/problems/count-complete-tree-nodes
*/
/*
    Solution Approach: Recursive DFS
    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of nodes in the tree

    Explanation:
        - Traversing the whole tree recursively.
        - If the node is null, that it's the end of the path,
            hence returning 0.
        - Otherwise, returning the sum of the left and right subtrees
            plus one for the current node.
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int countleft = countNodes(root->left);
        int countright = countNodes(root->right);

        return (countleft + countright) + 1;
    }
};
