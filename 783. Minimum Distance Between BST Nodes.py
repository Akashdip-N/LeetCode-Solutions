"""
https://leetcode.com/problems/minimum-distance-between-bst-nodes
(same as 530. Minimum Absolute Difference in BST)
https://leetcode.com/problems/minimum-absolute-difference-in-bst
"""


class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
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
