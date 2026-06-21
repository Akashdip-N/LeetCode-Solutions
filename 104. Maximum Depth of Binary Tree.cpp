/*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/
/*
    Solution Approach: Recursive DFS, passing current level by value

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of nodes in the tree

    Explanation:
        - Using a helper function to traverse the tree recursively.
        - The current level is passed by value, so each recursive call
            has its own copy of the current level.
        - The maximum depth found so far is updated if the current level
            exceeds it.
        - The function continues to traverse the left and right subtrees,
            incrementing the current level by 1 for each recursive call.
*/
class Solution {
public:
    void depth(TreeNode* node, int currentLevel, int& maxDeep) {
        if (!node) return;

        // Update the maximum depth found so far
        if (currentLevel > maxDeep)
            maxDeep = currentLevel;

        // Pass the next level down (by value, not by reference)
        depth(node->left, currentLevel + 1, maxDeep);
        depth(node->right, currentLevel + 1, maxDeep);
    }

    int maxDepth(TreeNode* root) {
        int dep = 0;
        depth(root, 1, dep);

        return dep;
    }
};

/****************************************************************************************/
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
        if(root == nullptr) return 0;

        // Get the depth of both subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The depth of the current node is 1 plus the deeper of its two children
        return 1 + max(leftDepth, rightDepth);
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
