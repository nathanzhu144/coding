#  WEdnesday Nov 21st, 2018 9:36 pm Ft. Lauderdale FL
#  Idea is pretty simple - use list comprehension

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root:
            return 0
        if not root.children:
            return 1
        return max([self.maxDepth(i) for i in root.children]) + 1