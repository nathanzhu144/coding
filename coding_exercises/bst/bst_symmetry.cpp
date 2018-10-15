#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>

using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

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

// bool check_symmetry(Node* root){
//     return check_symmetry_helper(root, root);
// }
bool check_symmetry_one(Node *root){
    //If root is nullptr, is symmetric, return true
    if(!root) { return true; }

    //If both children are nullptr, return true
    if(!root->left && !root->right){
        return true;
    }

    //If one child, but not both are not nullptr, return false;
    if(!root->left || !root->right){
        return false;
    }

    if(root->left->data != root->right->data){
        return false;
    }

    //Check if both left & right subtrees are symmetric
    return check_symmetry_one(root->left) &&
           check_symmetry_one(root->right);
}

// Driver program 
int main() 
{ 
    // Let us construct the Tree shown in the above figure 
    Node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(2); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(3); 

    Node *root3        = newNode(3);
    root3->left        = newNode(2); 
    root3->right       = newNode(2); 


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
    cout << "Symmetry 0 or 1: " << check_symmetry_one(root) << endl; 
    cout << "Symmetry 0 or 1: " << check_symmetry_one(root2) << endl; 
    cout << "Symmetry 0 or 1: " << check_symmetry_one(root3) << endl; 

    return 0; 
} 