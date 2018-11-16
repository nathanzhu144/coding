#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>
#include <vector>

/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Nathan Zhu
 * 11:28 am at State Stree Starbucks
 * November 1st, 2018
 * 
 * The LCA of a binary tree is the parent of p and q farthest away from root
 */

using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

///////////////////////////////////////
//        LCA for non-bsts          //
//////////////////////////////////////


/**
 * Insights
 * 
 * Node *left tracks if p or q are found on the left side of the tree, and if so the LCA
 * 
 * Node *right tracks if p or q are found on the right side of the tree and the LCA
 * 
 * 
 * If in any recursive stack frame, p and q are found in different sides of the tree,
 * that node must be the LCA of p and q.
 * 
 * If p and q are found on the right side of the subtree, Node* left is NULL,
 * so we return the lowestCommonAncestor(root->right, p, q)
 * 
 * We do same for if p and q are found on left subtree.
 */
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        //Cannot find p or q
        if(root == NULL){
            return root;
        }
        
        //If current node is p or q, p or q is the LCA
        if(root == p || root == q){
            return root;
        }
        
        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);
        
        //p and q are on different sides of the tree, so root is the LCA of p and q
        if(left && right){
            return root;
        }
        if(!left){
            return right;
        }
        else{
            return left;
        }
}

///////////////////////////////////////
//        LCA for BST               //
//////////////////////////////////////

//Note that this only works with BSTs
Node* lowestCommonAncestor_BST(Node* root, Node* p, Node* q) {
        if(!root){ return NULL; }
        
        //If p->data and q->data are less than root, LCA must be on left
        if(p->data < root->data && q ->data < root->data){
            return lowestCommonAncestor(root->left, p, q);
        }
        
        //If p->data and q->data are greater than root, LCA must be on right
        if(p->data > root->data && q ->data > root->data){
            return lowestCommonAncestor(root->right, p, q);
        }
        
        //If none of these conditions, this root must be LCA
        return root;
    }


///////////////////////////////////
//      Utility functions        //
///////////////////////////////////


// Utility function to create new Node 
Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data  = data; 
    temp->left  = temp->right = NULL; 
    return (temp); 
}

Node *constructBST(vector<int> arr){

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


// Driver program 
int main() 
{ 
    // Let us construct the Tree shown in the above figure 
    Node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(5); 
    root->left->left  = newNode(3); 
    root->left->right = newNode(4); 
    root->right->left  = newNode(4); 
    root->right->right = newNode(1); 
    root->right->right->right = newNode(1); 
    root->left->left->left = newNode(2); 

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

   
    //printLevelOrder(root2);
    //cout << "Symmetry 0 or 1: " << is_foldable(root->left, root->right) << endl; 

    return 0; 
} 