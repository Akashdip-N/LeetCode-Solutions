/*
    https://leetcode.com/problems/binary-tree-inorder-traversal/
*/
/*
    Solution Approach: Recursive Approach (using DFS)

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Create a helper function, which would take the root node.
        - If the root is null, return nothing.
        - Inside the helper function, recursively call the left child of the root.
        - After that, push the value of the root into the vector.
        - Finally, recursively call the right child of the root.
        - Return the vector containing the inorder traversal of the binary tree.
        - The main function calls the helper function with the root node
            and returns the vector.
*/
class Solution {
public:
    void fun(TreeNode* root, vector<int> &a){
        if(!root)
            return;

        fun(root->left, a);
        a.push_back(root->val);
        fun(root->right, a);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        fun(root, a);
        return a;
    }
};

/*********************************************************************************/
/*
    Solution Approach: Iterative Approach (using Stack)

    Time Complexity: O(n)
    Space Complexity: O(n)
    n = number of nodes in the tree

    Explanation:
        - Use a stack to keep track of nodes.
        - Start from the root and go as left as possible,
            pushing each node onto the stack.
        - When you reach a null node,
            pop from the stack, add the node's value to the result, and
                then move to the right child.
        - Repeat until both the stack is empty and there are
            no more nodes to process.
        - Return the result vector containing the
            inorder traversal of the binary tree.
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            result.push_back(current->val);
            current = current->right;
        }

        return result;
    }
};
