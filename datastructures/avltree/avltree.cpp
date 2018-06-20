// C program to insert a node in AVL tree
// An AVL tree has the 
/*
*   An AVL Tree has the following properties.
*
*   An AVL tree is a binary search tree which has the following properties:
*   - The sub-trees of every node differ in height by at most one.
*   - Every sub-tree is an AVL tree.
*
*
*   If there are n nodes in an AVL Tree, the minimum
*   height is the floor of logn.
*
*   If there are n nodes in AVL tree, the maximum height 
*   cannot exceed 1.44 * logn.
*
*   If height of AVL tree is h, the maximum number of nodes
*   can be 2^(h + 1) - 1.
*
*   The minimum of nodes in a tree with height h can be 
*   represented as:
*   N(h) = N(h-1) + N(h-2) + 1 
*   for n>2 where N(0) = 1 and N(1) = 2.
*
*   The complexity of searching, inserting, and deleting in 
*   AVL is O(logn n)
*/

#include <iostream>

class Node
{
    //Node is added as leaf, so height is 1.
    public:
    Node(int key_in):key(key_in), left(nullptr), right(nullptr), height(1){
    }

    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b);
 
// A utility function to get the height of the tree
int height(struct Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}
 
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}



Node *right_rotate(Node* input_node){
    Node *pivot = input_node->left;
    Node *new_left = input_node->left->right;

    //Rotation
    pivot->right = input_node;
    input_node->left = new_left;

    input_node->height = max(height(input_node->left), height(input_node->right)) + 1;
    pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
}

          
Node *left_rotate(Node* input_node){
    Node *pivot = input_node->right;
    Node *new_right = input_node->right->left;

    //Rotation
    pivot->left = input_node;
    input_node->right = new_right;

    input_node->height = max(height(input_node->left), height(input_node->right)) + 1;
    pivot->height = max(height(pivot->left), height(pivot->right)) + 1;
}
 
// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == nullptr){
        Node* temp = new Node(key);
        return temp;
    }
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  left_rotate(node->left);
        return right_rotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != nullptr)
    {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
  Node *root = nullptr;
 
  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  preOrder(root);
 
  return 0;
}