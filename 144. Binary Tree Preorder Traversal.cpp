/*
    https://leetcode.com/problems/binary-tree-preorder-traversal
*/
/*
    Solution Approach: Recursive Approach (using DFS)

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Using a recursive helper function, we traverse the tree in preorder.
        - If the current node is null, we return.
        - For inorder traversal, we first visit the root node,
            then recursively visit the left subtree, and finally the right subtree.
        - The main function initializes a vector to store the elements
            and calls the helper function with the root node.
        - Finally, it returns the vector containing the preorder traversal of the binary tree.
*/
class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &elements){
        if(!root)
            return;

        elements.push_back(root->val);
        preOrder(root->left, elements);
        preOrder(root->right, elements);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> elements;
        preOrder(root, elements);

        return elements;
    }
};

/******************************************************************************/
/*
    Solution Approach: Iterative Approach (using Stack)

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - We use a stack to keep track of nodes.
        - First we push the root node onto the stack.
        - While the stack is not empty, we pop the top node,
            add its value to the result vector,
                then we traverse the right child first,
                    followed by the left child.
        - This ensures that we visit the root node first,
            then the left subtree, and finally the right subtree.
        - Finally, we return the vector containing the preorder
            traversal of the binary tree.
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> elements;
        stack<TreeNode*> nodeStack;

        if (root)
            nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* currentNode = nodeStack.top();
            nodeStack.pop();
            elements.push_back(currentNode->val);

            if (currentNode->right)
                nodeStack.push(currentNode->right);

            if (currentNode->left)
                nodeStack.push(currentNode->left);
        }

        return elements;
    }
};
