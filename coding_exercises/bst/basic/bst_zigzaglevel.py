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