/**
 *  Nathan Zhu
 *  10/20/2018, 10:25 pm, right after Code for Good at Columbus, Ohio.
 *   
 *  I am exhausted.  Got like 3.5 hrs of sleep last night.
 * 
 *  BST isomorphic question.
 * 
 *  https://www.geeksforgeeks.org/tree-isomorphism-problem/
 *  
 *  How to check if two trees can be made the same by swapping 
 *  the subtrees of some nodes?
 */

#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

///////////////////////////////////////
//        Check bst isometric       //
//////////////////////////////////////

bool is_isometric(Node *tree1, Node *tree2)
{
    //only way to return true is if both nullptr
    if (!tree1 || !tree2)
    {
        return !tree1 && !tree2;
    }

    if (tree1->data != tree2->data)
    {
        return false;
    }

    //Either tree is swapped or tree is not swapped
    return ((is_isometric(tree1->left, tree2->right)   
      && is_isometric(tree1->right, tree2->left)) 
      || (is_isometric(tree1->left, tree2->left) 
      && is_isometric(tree1->right, tree2->right)));
}

///////////////////////////////////
//      Utility functions        //
///////////////////////////////////

// Utility function to create new Node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

void printLevelOrder(Node *root)
{

    if (!root)
    {
        return;
    }

    deque<Node *> container;
    container.push_back(root);

    while (1)
    {
        int size = container.size();

        if (!container.size())
        {
            break;
        }

        while (size > 0)
        {
            Node *temp = container.front();
            cout << temp->data << " ";
            container.pop_front();

            if (temp->left)
            {
                container.push_back(temp->left);
            }
            if (temp->right)
            {
                container.push_back(temp->right);
            }
            --size;
        }
        std::cout << std::endl;
    }
}

Node *insert(Node *n, int a)
{
    if (n == NULL)
    {
        return newNode(a);
    }

    if (n->data < a)
    {
        n->right = insert(n->right, a);
    }
    else if (n->data > a)
    {
        n->left = insert(n->left, a);
    }

    return n;
}

// Driver program
int main()
{
    // Let us construct the Tree shown in the above figure
    // Let us create trees shown in above diagram 
    Node *n1 = newNode(1); 
    n1->left        = newNode(2); 
    n1->right       = newNode(3); 
    n1->left->left  = newNode(4); 
    n1->left->right = newNode(5); 
    n1->right->left  = newNode(6); 
    n1->left->right->left = newNode(7); 
    n1->left->right->right = newNode(8); 
  
    Node *n2 = newNode(1); 
    n2->left         = newNode(3); 
    n2->right        = newNode(2); 
    n2->right->left   = newNode(4); 
    n2->right->right   = newNode(5); 
    n2->left->right   = newNode(6); 
    n2->right->right->left = newNode(8); 
    n2->right->right->right = newNode(7); 

    Node *root2 = NULL;
    root2 = insert(root2, 3);
    insert(root2, 8);
    insert(root2, 10);
    insert(root2, 15);
    insert(root2, -1);
    insert(root2, -2);
    insert(root2, -7);
    insert(root2, 12);

    //printLevelOrder(root2);
    //Should be 1
    cout << "Isometric 0 or 1: " << is_isometric(n1, n2) << endl;
    //Should be 0
    cout << "Isometric 0 or 1: " << is_isometric(root2->left, root2->right) << endl;

    return 0;
}