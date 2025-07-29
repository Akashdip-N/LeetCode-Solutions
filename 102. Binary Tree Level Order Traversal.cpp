/*
    https://leetcode.com/problems/binary-tree-level-order-traversal
*/
/*
    Solution Approach: Using Breadth-First Search (BFS)

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the binary tree

    Explanation:
        - Using a queue to perform level order traversal.
        - For each level, we store the values of the nodes in a vector.
        - Using a for loop to iterate through the nodes at the current level.
        - After processing all nodes at the current level,
            we add the vector to the result.
        - Continue until all levels are processed.
        - The result will contain vectors of node values for each level.
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                // Pusing the left and right children to the queue if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};
