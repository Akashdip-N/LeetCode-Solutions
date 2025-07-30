/*
    https://leetcode.com/problems/minimum-depth-of-binary-tree
*/
/*
    Solution Approach: Using Recursion

    Time Complexity: O(n)
    Space Complexity: O(h)
    n = number of nodes in the tree
    h = height of the tree

    Explanation:
        - If the root is null,
            that means either the tree is empty or we have reached a leaf node,
                so we return 0.
        - If the node is a leaf node i.e. both the left and right nodes are null,
            we return 1 as the minimum depth.
        - If one of the children is null, we only consider the other child,
            and return the minimum depth of that subtree plus 1.
        - If both children are present, we call the function recursively on both children,
            and return the minimum of the two depths plus 1.
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        // Leaf node check
        if (!root->left && !root->right) return 1;

        // One sided tree check
        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

/****************************************************************************************/
/*
    Solution Approach: Iterative BFS, using queue

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Using a queue to perform level order traversal.
        - Each time we process a level, we increment the depth.
        - If we encounter a leaf node (both left and right children are null),
            we return the current depth.
        - If the node has left or right children, we add them to the queue.
        - The process continues until we find a leaf node.
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);

        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            depth++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check if it's a leaf node
                if (!node->left && !node->right)
                    return depth;

                // Add children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }
};

/****************************************************************************************/
/*
    Solution Approach: Iterative DFS, using stack

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Using a stack to perform depth-first traversal.
        - Each time we process a node, we check if it's a leaf node.
        - If it is, we return the current depth.
        - If the node has left or right children,
            we push them onto the stack with the updated depth.
        - The process continues until we find a leaf node.
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int minDepthVal = INT_MAX;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});

        while (!s.empty()) {
            auto [node, depth] = s.top();
            s.pop();

            // Leaf node found
            if (!node->left && !node->right)
                minDepthVal = min(minDepthVal, depth);

            if (node->left) s.push({node->left, depth + 1});
            if (node->right) s.push({node->right, depth + 1});
        }

        return minDepthVal;
    }
};
