#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#include <stack>

/**
 *  Nathan Zhu
 *  October 20th, 2018 10:53 pm
 *  
 *  Foundry Lofts on bed - after Code for Good hackathon.  Want to go to bed.
 * 
 *  Doing bst preorder iterative and recursively
 */

using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

/////////////////////////////////////////
//           Preorder Print            //
/////////////////////////////////////////
void pre_order_rec(Node* n){
    if(!n) return;

    cout << n->data << " ";
    pre_order_rec(n->left);
    pre_order_rec(n->right);
}

//Node that pre-order iterative is exactly the same 
//as a DFS
void preorder_iterative(Node* n){
    if(!n) return;

    stack<Node*> tree;
    Node* current = n;
    tree.push(n);

    while(!tree.empty()){
        Node* temp = tree.top();
        tree.pop();
        cout << temp->data << " ";

        //Pushing right node on top of stacl
        if(temp->right){
            tree.push(temp->right);
        }
        //Right node is now under left node
        if(temp->left){
            tree.push(temp->left);
        }
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

    preorder_iterative(root2);
    cout << endl;
    pre_order_rec(root2);

    return 0;
}