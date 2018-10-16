/**
 *  https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 * 
 *  https://www.youtube.com/watch?v=Dte6EF1nHNo
 * 
 */
 
 #include <stdlib.h>
#include <deque>
#include <iostream>

using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

//////////////////////////////////
//     BST to DLL functions     //
//////////////////////////////////

// Joins two circular linked lists together
// Requires two circular linked lists
Node* join(Node* a, Node * b){
    if(!a) return b;
    if(!b) return a;

    Node* a_end = a->left;
    Node *b_end = b->left;

    a_end->right = b;
    a->left = b_end;

    b_end->right = a;
    b->left = a_end;

    return a;
}

Node* bst_to_DLL(Node* root){
    if(!root) return root;

    Node* left = bst_to_DLL(root->left);
    Node* right = bst_to_DLL(root->right);

    root->left = root;
    root->right = root;

    Node* combined = join(left, root);
    combined = join(root, right);

    return combined;
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
