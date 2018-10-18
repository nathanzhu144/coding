/*
*   Nathan Zhu
*   znathan
*   Wednesday October 17th, 2018 6/l24 am
*  
*   https://www.geeksforgeeks.org/maximum-width-of-a-binary-tree/
* 
*   How to find width of a binary tree?
*
*   1. Using level order traversal, iterate thru each order of tree
*      See which one is widest.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int height(Node *a);

/////////////////////////////////////////
//           BST Width                 //
/////////////////////////////////////////

//Check notes at top for implement
int bst_width(Node *n)
{
    if (!n)
        return 0;

    int max_width = 0;
    queue<Node *> tree;
    tree.push(n);

    while (!tree.empty())
    {
        int tree_width = tree.size();

        max_width = max(max_width, tree_width);

        //Pushing next level of nodes down on
        while (tree_width)
        {
            if (tree.front()->left)
            {
                tree.push(tree.front()->left);
            }
            if (tree.front()->right)
            {
                tree.push(tree.front()->right);
            }
            tree.pop();

            tree_width--;
        }
    }

    return max_width;
}

/////////////////////////////////////////
//           Helper functions          //
/////////////////////////////////////////
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

int main()
{

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
    cout << "BST diameter root should be 3: " << bst_width(root) << endl;

    Node *root2 = NULL;
    root2 = insert(root2, 3);
    insert(root2, 8);
    insert(root2, 10);
    insert(root2, 15);
    insert(root2, -1);
    insert(root2, -2);
    insert(root2, -7);
    insert(root2, 12);
    printLevelOrder(root2);

    cout << "BST diameter root2 should be 2: " << bst_width(root2) << endl;

    Node* root3 = NULL;
    cout << "BST diameter root3 should be 0: " << bst_width(root3) << endl;

    Node* root4 = NULL;
    root4 = insert(root4, 3);
    insert(root4, 8);
    insert(root4, 10);
    insert(root4, 15);
    insert(root4, -1);
    insert(root4, 13);
    insert(root4, 11);
    insert(root4, -3);
    insert(root4, 7);
    insert(root4, 3);
    insert(root4, 4);
    insert(root4, 6);
    insert(root4, 14);
    insert(root4, 5);
    insert(root4, 2);
    insert(root4, -7);
    insert(root4, 12);
    insert(root4, -4);
    insert(root4, -5);
    insert(root4, 9);
    insert(root4, 16);
    insert(root4, 18);
    insert(root4, 19);
    insert(root4, 17);
    printLevelOrder(root4);
    cout << "BST diameter root4 should be 5: " << bst_width(root4) << endl;

    Node* root5 = NULL;
    root5 = insert(root5, 3);
    cout << "BST diameter root5 should be 1: " << bst_width(root5) << endl;
    
    return 0;
}

int height(Node *a)
{
    if (!a)
        return 0;

    return 1 + max(height(a->left), height(a->right));
}