#  Nathan Zhu
#  Nov 15th, 2018 10 pm
#  
#  This is a leetcode easy
#
#  We want to change a sorted array to a height-balanced BST, where
#  the depth of each two subtrees can never differ by one.
#
#  It is very easy.  Pick the middle element.
#
#  Then, recursively assign the left and right parts of the array to it
#
#           [1, 2, 3, 4, 5]
#
#            3
#          /   \
#      [1, 2]   [4, 5]
#
#   Etc...

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def zigzagLevelOrder(root):
    """
    :type root: TreeNode
    :rtype: List[List[int]]
    """
    if not root:
        return []
    
    returned = []
    children = [root]
    reverse = False
    
    while children:
        level = len(children)
        temp = []
        for i in children:
            temp.append(i.val)
        
        if not reverse:
            returned.append(temp)
        else:
            returned.append(temp[::-1])
        reverse = not reverse
        
        while level:
            front = children.pop(0)
            if front.left:
                children.append(front.left)
            if front.right:
                children.append(front.right)
            level -= 1
            
    return returned

def sortedArrayToBST(nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        
        def helper(nums, start, end):
            if start > end:
                return None

            m = (start + end) / 2
        
            temp = Node(nums[m])
            temp.left = helper(nums, start, m - 1)
            temp.right = helper(nums, m + 1, end)

            return temp
            
        return helper(nums, 0, len(nums) - 1)

if __name__ == "__main__":
    print(zigzagLevelOrder(sortedArrayToBST([1, 2, 3, 4, 5, 6, 7, 8])))

