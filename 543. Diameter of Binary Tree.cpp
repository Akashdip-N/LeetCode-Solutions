/*
    https://leetcode.com/problems/diameter-of-binary-tree
*/
/*                  LITTLE COMPLICATED PROBLEM             */
/*
    Solution Approach: Recursive Depth-First Search (DFS)

    * Going to the max depth of the left and right subtree,
        and storing the sum of the depth of the left and right subtree.
    * Comparing the current diameter with the largest diameter found so far.
    * Returning 1 + the largest diameter, because
        the root will be 1 so,
            the answer should be 1 + the largest diameter.
*/

class Solution {
    private:
        int height(TreeNode* node, int& largestDiameter) {
            if (node == nullptr)
                return 0;

            int leftHeight = height(node->left, largestDiameter);
            int rightHeight = height(node->right, largestDiameter);
            int diameter = leftHeight + rightHeight;

            largestDiameter = max(largestDiameter, diameter);

            return 1 + max(leftHeight, rightHeight);
        }

    public:
        int diameterOfBinaryTree(TreeNode* root) {
            int largestDiameter = 0;
            height(root, largestDiameter);
            return largestDiameter;
        }
};
