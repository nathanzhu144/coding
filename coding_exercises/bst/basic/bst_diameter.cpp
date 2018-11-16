/*
*   Nathan Zhu
*   znathan
*   Wednesday October 17th, 2018  11:39 pm
*  
*   https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
* 
*   The diameter of a binary search tree is the longest path 
*   between two leaves.  Note that this longest path does not necessarily
*   include the root node.
*
*   If it does include the root node, 
*   it is height(node->left) + height(node->right) + 1
*
*   If it does not include root node,
*   it is max(bst_diameter(node->left), bst_diamter(node->right))
*/

#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#include <stack>
#include <algorithm>


using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};


int height(Node *a);

/////////////////////////////////////////
//           BST Diameter              //
/////////////////////////////////////////

//Check notes at top for implement
int bst_diameter(Node* n){
    if(!n) return 0;

    return std::max(height(n->left) + height(n->right) + 1, 
           std::max(bst_diameter(n->left), bst_diameter(n->right)));
}

/////////////////////////////////////////
//           Helper functions          //
/////////////////////////////////////////
// Utility function to create new Node 
Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data  = data; 
    temp->left  = temp->right = NULL; 
    return (temp); 
} 

void printLevelOrder(Node *root){

    if(!root) { return; }

    deque<Node*> container;
    container.push_back(root);

    while(1){
        int size = container.size();

        if(!container.size()){ break; }

        while(size > 0){
            Node *temp = container.front();
            cout << temp->data << " ";
            container.pop_front();

            if(temp->left){
                container.push_back(temp->left);
            }
            if(temp->right){
                container.push_back(temp->right);
            }
            --size;
        }
        std::cout << std::endl;
    }
}

Node* insert(Node* n, int a){
    if (n == NULL){ return newNode(a); }

    if (n->data < a){
        n->right = insert(n->right, a);
    }
    else if(n->data > a){
        n->left = insert(n->left, a);
    }

    return n;
}


int main(){
    Node *root2   = NULL;
    root2 = insert(root2, 3);
    insert(root2, 8);
    insert(root2, 10);
    insert(root2, 15);
    insert(root2, -1);
    insert(root2, -2);
    insert(root2, -7);
    insert(root2, 12);
    printLevelOrder(root2);

    cout << "BST diameter root2: " << bst_diameter(root2);

    return 0;
}

int height(Node *a){
    if (!a) return 0;

    return 1 + max(height(a->left), height(a->right));
}