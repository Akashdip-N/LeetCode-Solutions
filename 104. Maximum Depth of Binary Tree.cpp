/*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

/*
    Solution Approach: Recursive DFS

    Time Complexity: O(n)
    Space Complexity: O(n)

    * Recursively; Calculating and returning the maximum depth using DFS,
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/***********************************************************************/
/*
    Solution Approach: Using BFS (using queue)

    * Keeping a depth variable to track the depth of the tree.
    * Storing the nodes of each level in a queue.
    * Iterating through each level and updating the depth.
    * Returning the final depth.
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};

/***********************************************************************/
/*
    Solution Approach: Iterative DFS, using stack

    * Using stack to store the node and its depth.
    * Iterating through each level and updating the depth.
    * Comparing and storing the maximum depth.
    * Returning the final depth.
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int depth = 0;

        while(!st.empty()) {
            auto [node, d] = st.top();
            st.pop();

            depth = max(depth, d);

            if(node->left)
                st.push({node->left, d + 1});

            if(node->right)
                st.push({node->right, d + 1});
        }

        return depth;
    }
};
