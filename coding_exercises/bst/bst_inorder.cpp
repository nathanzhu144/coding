#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#include <stack>

/**
 *  Nathan Zhu
 *  October 16th, 2018
 *  
 *  Starbucks, State Street 12:15 pm
 *  
 *  How to print a binary search tree inorder.
 */

using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

/////////////////////////////////////////
//           Inorder Print             //
/////////////////////////////////////////
void in_order_rec(Node* n){
    if(!n) return;

    in_order_rec(n->left);
    cout << n->data << " ";
    in_order_rec(n->right);
}

void in_order_iterative(Node* n){
    if(!n) return;

    stack<Node*> tree;
    Node* current = n;

    while(current || !tree.empty()){
        //Move as far down and left as we can
        //until we hit nullptr
        while(current){
            tree.push(current);
            current = current->left;
        }

        //current must be null at this point
        current = tree.top();
        tree.pop();

        cout << current->data << " ";

        //Traverse right subtree
        current = current->right;
    }
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

    in_order_iterative(root2);
    cout << endl;
    in_order_rec(root2);

    return 0;
}