#  Nathan Zhu
#  Foundry Lofts 2nd Floor Sunday October 28th, 12:11 am
#
#  How to do you validate a BST?
#
#  1. Pass a floor and ceiling parameter in, and make sure 
#     that all the nodes on the left have a val < datum value
#     nad all nodes on rright have a val > datum value
#
#  2. Do an inorder traversal and see if it is increasing. 
#     This is easy.
#
#  I do method 1 in this example

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


#######################################
#        Interesting Functions        #
#######################################
#
#   Return true if
#          > Rot is NULL
#          > or if  
#                floor < root.val < ceiling AND left and right subtrees are valid
# 
def validateTree(root, floor = float('-inf'), ceiling = float('inf')):
    return not root or floor < root.val < ceiling and \
               validateTree(root.left, floor, root.val) and \
               validateTree(root.right, root.val, ceiling)

#######################################
#            Helper  Functions        #
#######################################

def buildTree(inorder, postorder):
    if not inorder or not postorder:
        return None

    root = Node(postorder.pop())
    i = inorder.index(root.val)

    root.right = buildTree(inorder[i + 1:], postorder)
    root.left = buildTree(inorder[:i], postorder)

    return root

def print_preorder(node):
    if not node:
        return

    print_preorder(node.left)
    print(node.val)
    print_preorder(node.right)

def print_postorder(node):
    if not node:
        return

    print_postorder(node.left)
    print_postorder(node.right)
    print(node.val)


if __name__ == "__main__":
    print(validateTree(buildTree([10, 11, 12, 19, 21, 25, 26], [10, 11, 12, 21, 26, 25, 19])))
    