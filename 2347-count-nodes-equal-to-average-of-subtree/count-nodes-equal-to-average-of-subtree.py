# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root):
        self.answer = 0

        def dfs(node):
            if not node:
                return 0, 0 

            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)

            subtree_sum = left_sum + right_sum + node.val
            subtree_count = left_count + right_count + 1

            if node.val == subtree_sum // subtree_count:
                self.answer += 1

            return subtree_sum, subtree_count

        dfs(root)
        return self.answer