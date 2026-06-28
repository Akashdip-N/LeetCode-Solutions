/*
    https://leetcode.com/problems/check-completeness-of-a-binary-tree
*/
/*
    Solution Approach:- BFS using queue.

    Time Complexity:- O(N)
    Space Complexity:- O(N)
    N = number of nodes in the tree

    Explanation:-
        * Here what are checking is if we enounter a null node.
        * Then we would make sure that after encountering a null node,
            then we should not encounter any more non-null nodes.
        * That would make sure that the tree is complete.
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool ch = false;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node)
                ch = true;
            else{
                if(ch) return false;

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};
