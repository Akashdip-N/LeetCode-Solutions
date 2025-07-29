/*
    https://leetcode.com/problems/binary-tree-postorder-traversal
*/
/*
    Solution Approach: Recursive Approach

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Using a recursive helper function, we traverse the tree in postorder.
        - If the current node is null, we return.
        - For postorder traversal, we first recursively visit the left subtree,
            then the right subtree, and finally visit the root node.
        - The main function initializes a vector to store the elements
            and calls the helper function with the root node.
        - Finally, it returns the vector containing the postorder traversal
            of the binary tree.
*/
class Solution {
public:
    void postOrder(TreeNode* root, vector<int> &nodes){
        if(!root) return;

        postOrder(root->left, nodes);
        postOrder(root->right, nodes);
        nodes.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postOrder(root, nodes);
        return nodes;
    }
};

/*******************************************************************************************/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> s;
        TreeNode* lastVisited = nullptr;

        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            TreeNode* peekNode = s.top();
            if (!peekNode->right || peekNode->right == lastVisited) {
                nodes.push_back(peekNode->val);
                s.pop();
                lastVisited = peekNode;
            } else {
                root = peekNode->right;
            }
        }

        return nodes;
    }
};
