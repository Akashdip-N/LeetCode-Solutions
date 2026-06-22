/*
    https://leetcode.com/problems/find-mode-in-binary-search-tree
*/
/*
    Solution Approach: Recursive DFS, using in-order traversal

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of nodes in the tree

    Explanation:
        - Given a BST (Binary Search Tree), the in-order traversal will give the values of the nodes in sorted order.
        - We will perform an in-order traversal of the tree, keeping track of the current value and its count.
        - We will also keep track of the maximum count of any value seen so far.
        - If the current value's count matches the maximum count, we will add it to the modes vector.
        - If the current value's count exceeds the maximum count,
            we will update the maximum count and reset the modes vector to only include the current value.
*/
class Solution {
private:
    void inOrder(TreeNode* root, TreeNode*& prev, int& current_count, int& max_count, vector<int>& modes) {
        if (root == nullptr) return;

        inOrder(root->left, prev, current_count, max_count, modes);

        // Edge case: First node we are visiting, so we initialize current_count to 1
        if (prev == nullptr) {
            // First node we are visiting
            current_count = 1;
        } else if (root->val == prev->val) {
            // Duplicate value
            current_count++;
        } else {
            // New value
            current_count = 1;
        }

        // Track the current node as 'prev' for the next step
        prev = root;

        if (current_count == max_count) {
            modes.push_back(root->val);
        } else if (current_count > max_count) {
            max_count = current_count;
            modes.clear();
            modes.push_back(root->val);
        }

        inOrder(root->right, prev, current_count, max_count, modes);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        TreeNode* prev = nullptr;
        int current_count = 0;
        int max_count = 0;

        inOrder(root, prev, current_count, max_count, modes);
        return modes;
    }
};
