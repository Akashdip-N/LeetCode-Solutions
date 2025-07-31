/*
    https://leetcode.com/problems/symmetric-tree/
*/
/*
    Solution Approach: Recursive Method

    Time Complexity: O(n)
    Space Complexity: O(h)
    n = number of nodes in the tree
    h = height of the tree

    Explanation:
        - Using a helper function to check if the left and right subtrees are symmetric.
        - If the value of the left and right nodes are equal, we return true.
        - If either of the nodes are null, we return false.
        - If the left and right node values are not equal, we return false.
        - We call the helper function recursively for the
            left child of the left node and
                the right child of the right node, and
                    vice versa.
*/
class Solution {
public:
    bool checkChildNodes(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;

        if(left->val != right->val) return false;

        return
            checkChildNodes(left->left, right->right) &&
            checkChildNodes(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return true;
        return checkChildNodes(root->left, root->right);
    }
};

/*******************************************************************************************/
/*
    Solution Approach: Iterative Method using Queue

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - We use a queue to perform a level-order traversal of the tree.
        - We push the left and right children of the root into the queue.
        - For each pair of nodes, the following checks are performed:
            - If both nodes are null,
                i.e. it's the leaf node,
                    continue to the next pair.
            - If one node is null and the other is not,
                i.e. the tree is not symmetric,
                    return false.
            - If the values of the nodes are not equal,
                i.e. the tree is not symmetric,
                    return false.
            - Push the children of the left and right nodes in reverse order
                to maintain symmetry:
                - left->left and right->right
                - left->right and right->left
        - If all pairs pass the checks, return true indicating the tree is symmetric.
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();

            // Leaf node check
            if (!left && !right) continue;

            // One node is null, the other is not, tree is not symmetric
            if (!left || !right) return false;

            // Values of the nodes must be equal for symmetry
            if (left->val != right->val) return false;

            // Push children in reverse order for symmetry check
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};
