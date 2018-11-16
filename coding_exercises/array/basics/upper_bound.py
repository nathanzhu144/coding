def upper_bound(arr, target):
    l = 0
    r = len(arr) - 1
    while r > l:
        m = (l + r) / 2
        if target > arr[m]:
            l = m + 1
        else:
            r = m - 1

    return l


class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None


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
        
            temp = TreeNode(nums[m])
            temp.left = helper(nums, start, m - 1)
            temp.right = helper(nums, m + 1, end)

            return temp
            
        return helper(nums, 0, len(nums) - 1)


if __name__ == "__main__":
    print(upper_bound([1, 2, 3], 4))
    print(upper_bound([1, 2, 2, 3], 3))
    print(upper_bound([1, 2, 2, 4, 7], 3))
    print(upper_bound([1, 2, 2, 4, 7], -1))
    sortedArrayToBST([2, 23, 34,45, 50])


