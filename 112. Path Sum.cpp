/*
    https://leetcode.com/problems/path-sum
*/
/*
    Solution Approach: Using Recursion

    Time Complexity: O(N)
    Space Complexity: O(H)
    N = number of nodes in the tree
    H = height of the tree

    Explanation:
        - We traverse the tree from root to the leaf nodes.
        - At each node, we subtract the node's value from the target sum.
        - Base case, where the tree is empty, we return false.
        - If we reach a leaf node and the target sum is zero, we return true.
        - If we reach a leaf node and the target sum is not zero, we return false.
        - We continue this process recursively
            for both left and right children of the node.
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        targetSum -= root->val;

        if (!root->left && !root->right) return targetSum == 0;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

/***************************************************************************************/
/*
    Solution Approach: Iterative Approach (Using Stack)

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of nodes in the tree

    Explanation:
        - We use a stack to keep track of nodes and their corresponding path sums.
        - Start with the root node and its value as the initial path sum.
        - While the stack is not empty, pop the top element.
        - Store the current node and its path sum.
        - Check if the current node is a leaf node (both left and right children are null),
            and if the path sum equals the target sum,
                return true.
        - If the current node has a right child,
            push it onto the stack with the updated path sum.
        - If the current node has a left child,
            push it onto the stack with the updated path sum.
        - If we finish processing all nodes and haven't found a valid path, return false.
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});

        while (!s.empty()) {
            TreeNode* node = s.top().first;
            int current_sum = s.top().second;
            s.pop();

            if (node->left == nullptr && node->right == nullptr)
                if (current_sum == targetSum)
                    return true;

            if (node->right != nullptr)
                s.push({node->right, current_sum + node->right->val});

            if (node->left != nullptr)
                s.push({node->left, current_sum + node->left->val});
        }

        return false;
    }
};
