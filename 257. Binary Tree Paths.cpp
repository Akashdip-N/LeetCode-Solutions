/*
    https://leetcode.com/problems/binary-tree-paths
*/
/*
    Approach:- dfs(Depth First Search) implementation.

    Time & Space Complexity: O(N),
        where N = number of nodes in the binary tree.

    Explanation:-
        * Using a helper function `dfs`, we traverse the binary tree.
        * If the current node is null, we return.
        * We append the current node's value to the path string.
        * Checking if the current node is a leaf node i.e.,
            both left and right children are null,
                we add the path to the result.
        * If not a leaf node, we append "->" to the path and
            continue the search for both left and right children.
        * Finally, we return the list of paths collected during the traversal.
*/

class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        if (node == nullptr)
            return;

        path += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
        } else {
            path += "->";
            dfs(node->left, path, paths);
            dfs(node->right, path, paths);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }
};
