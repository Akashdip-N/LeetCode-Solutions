"""
https://leetcode.com/problems/minimum-absolute-difference-in-bst
"""

"""
    https://leetcode.com/problems/minimum-absolute-difference-in-bst

    Solution Approach:- Using Inorder Traversal, going to the leftmost leaf node then tracking back

    Time Complexity:- O(N)
    Space Complexity:- O(H)
    N = number of nodes in the tree
    H = height of the tree

    Explanation:-
        * Checking the current node is null or not, if null then return
        * Then we would store the value of the leaf node in the variable
        * Then we are backtracking to the parent node
            and comparing and storing the minimum difference between the parent node and the child node
        * Then we are updaing the value of the parent node
            in the variable and then going to the right child node of the parent node
        * At the end we are returning the minimum difference between the parent node and the child node
"""


class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.min_diff = float("inf")
        self.prev_val = None

        def inOrder(node):
            if not node:
                return

            inOrder(node.left)

            if self.prev_val is not None:
                self.min_diff = min(self.min_diff, node.val - self.prev_val)

            self.prev_val = node.val
            inOrder(node.right)

        inOrder(root)
        return self.min_diff
