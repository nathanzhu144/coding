def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        returned = []
        tree = [root]
        
        while tree:
            temp = []
            
            tree_size = len(tree)
            
            while tree_size:      
                if tree[0].left is not None:
                    tree.append(tree[0].left)
                    temp.append(tree[0].left)
                if tree[0].right is not None:
                    tree.append(tree[0].right)
                    temp.append(tree[0].right)
                tree_size -= 1
                tree.pop(0)
                
            tree.append(temp)
            
        return returned

