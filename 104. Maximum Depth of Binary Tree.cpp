/*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/
/*
    Solution Approach: Recursive DFS

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Traversing the whole tree recursively.
        - If the node is null, that it's the end of the path,
            hence returning 0.
        - Otherwise, returning the maximum depth of the left and right subtrees
            plus one for the current node.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
        - If the node has left or right children, we add them to the queue.
        - The process continues until all levels are processed.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            depth++;
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
        - Each time we visit a node, we push it onto the stack with
                its current depth.
        - If the node is null, we skip it.
        - Otherwise, we update the maximum depth found so far.
        - We push the left and right children onto the stack with an
            incremented depth.
        - The process continues until the stack is empty.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int depth = 0;

        while(!st.empty()) {
            auto [node, d] = st.top();
            st.pop();

            depth = max(depth, d);

            if(node->left) st.push({node->left, d + 1});
            if(node->right) st.push({node->right, d + 1});
        }

        return depth;
    }
};
