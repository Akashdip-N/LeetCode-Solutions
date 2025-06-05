/*
    https://leetcode.com/problems/balanced-binary-tree
*/
/********** THIS IS A EASY PROBLEM, BUT IS REALLY DIFFICULT TO UNDERSTAND ********/
/***************************** BOTTOM UP APPROACH *******************************/
/*
    Solution Approach: Recursive Method, DFS

    Time Complexity: O(n),
        n = number of nodes in the tree

    Explanation:
        * Using a helper function to calculate the height of the tree,
            finding the maximum height of the left and right subtrees.
                so that we can get the height of the tree in O(n) time.
*/

class Solution {
public:
    /*
     * In this function,
        at first we check if the root is null, and if it is, return 0.

        Then we call node->left and node->right recursively,
            which means the function will traverse,
                first to the end most left node,
                    then to the same end most right node,
                        and calculate the height of the tree and return it.

            From there, the other nodes will be calculated,
                and the height of the tree will be returned to the previous node.
     */
    int height(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // Base case: if the root is null, the tree is balanced
        if(root == nullptr)
            return true;

        // Calculating the height of the left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Checking if the difference in heights is more than 1
        if(abs(leftHeight - rightHeight) > 1)
            return false;

        // Recursively check the left and right subtrees
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
