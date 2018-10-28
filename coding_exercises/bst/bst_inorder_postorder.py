#  Nathan Zhu
#  Foundry Lofts 2nd Floor Sunday October 28th, 12:03 am
#
#  https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

#  Inorder Traversal  [4, 8, 2, 5, 1, 6, 3, 7]
#  Post Traversal     [8, 4, 5, 2, 6, 7, 3, 1]
#
#
#  We set root as end of postorder traversal, and then
#  branch to left and right of tree based off of inorder traversal.
#
#    Inorder Traversal split in lowest stack frame  [4, 8, 2, 5]  | 1 |  [6, 3, 7]
#
#  WARNING: WILL BE WRONG IF YOU DO NOT BUILD RIGHT BEFORE LEFT
#  
#  1st
# 
#  Root = 1   (end of postorder)
#        ->   root.right  has inorder [6, 3, 7]
#                
# 
#  2nd 
#      
#  Root = 1 
#         \   Root = 3    
#                        ->   root.right has inorder [7]
#
#  3rd
#  
#  Root = 1 
#         \   Root = 3    
#     root.left has inorder [6]<-  \ Root = 7
#
#
#  4th (We are finished with right subtree)
#  
#                                     Root = 1 
#                                     /         \   
#     root.left has inorder [4, 8, 2, 5]      Root = 3    
#                                             /      \ 
#                                      Root = 6       Root = 7
#   
#    And so on..
# 
# 

class Node:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


#######################################
#        Interesting Functions        #
#######################################
def buildTree(inorder, postorder):
    if not inorder or not postorder:
        return None

    root = Node(postorder.pop())
    i = inorder.index(root.val)

    root.right = buildTree(inorder[i + 1:], postorder)
    root.left = buildTree(inorder[:i], postorder)

    return root

#######################################
#            Helper  Functions        #
#######################################

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
    print_preorder( buildTree([4,8,2,5,1,6,3,7], [8, 4, 5, 2, 6, 7, 3, 1]))
    print()
    print_postorder( buildTree([4,8,2,5,1,6,3,7], [8, 4, 5, 2, 6, 7, 3, 1]))