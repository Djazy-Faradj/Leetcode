# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, height, root) -> int: 
        if (root is None): return height
        if (root is not None): height += 1
        return max(self.helper(height, root.left), self.helper(height, root.right))

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.helper(0, root)