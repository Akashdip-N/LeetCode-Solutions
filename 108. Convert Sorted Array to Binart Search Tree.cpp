/*
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
/*
    Solution Approach: Recursive DFS, passing current level by value

    Time Complexity: O(N)
    Space Complexity: O(N)
    N = number of nodes in the tree

    Explanation:
        - Input array is sorted in ascending order,
            so the middle element of the array will be the root of the BST.
        - The left half of the array will be the left subtree,
            and the right half of the array will be the right subtree.
        - Recursively repeat the process for the left and right halves of the array.
*/
class Solution {
public:
    TreeNode* addNode(vector<int> a, int left, int right){
        if(left > right)
            return nullptr;

        int mid = (left + right)/2;
        TreeNode * temp = new TreeNode(a[mid]);

        temp->left = addNode(a, left, mid - 1);
        temp->right = addNode(a, mid + 1, right);

        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return addNode(nums, 0, nums.size() - 1);
    }
};
