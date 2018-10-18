/*
*   Nathan Zhu
*   znathan
*   Wednesday October 17th, 2018  7:41 am
*  
*   https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/
* 
*   Making a sorted array to a balanced BST in O(n).
*
*   C is constant because finding and linking middle to left and
*   right subtrees is constant time.
*
*   T(n) = 2T(N/2) + C
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
Node *newNode(int data);

/////////////////////////////////////////
//        Sorted arr to bst            //
/////////////////////////////////////////

Node* bst_arr_helper(Node *n, int* arr, int start, int end){
    if (start > end) return NULL;

    int middle = (start + end) / 2;
    
    n = newNode(arr[middle]);

    n->left = bst_arr_helper(n->left, arr, start, middle - 1);
    n->right = bst_arr_helper(n->right, arr, middle + 1, end);

    return n;
}

//Check notes at top for implement
Node* bst_arr(Node* n, int* arr, int arr_size){
    return bst_arr_helper(n, arr, 0, arr_size - 1);
}

/////////////////////////////////////////
//           Helper functions          //
/////////////////////////////////////////


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

void in_order(Node* n){
    if(!n) return;

    in_order(n->left);
    cout << n->data << " ";
    in_order(n->right);
}


int main(){
    //length 14
    int arr[] = {-1, 2, 3, 4, 6, 8, 11, 12, 15, 19, 23, 24, 25, 29};
    int arr2[] = {5};
    int arr3[] = {};
    int arr4[] = {4, 15, 16, 17, 19};

    Node* root = NULL;
    Node* root2 = NULL;
    Node* root3 = NULL;
    Node* root4 = NULL;

    cout << "Tree 1" << endl;
    cout << "----" << endl;
    cout << endl;
    root = bst_arr(root, arr, 14);
    printLevelOrder(root);
    cout << endl;
    in_order(root);
    cout << endl;
    cout << endl;

    root2 = bst_arr(root2, arr, 1);
    printLevelOrder(root2);
    cout << endl;

    root3 = bst_arr(root3, arr, 0);

    root4 = bst_arr(root4, arr, 5);
    printLevelOrder(root4);
    cout << endl;


    return 0;
}

int height(Node *a){
    if (!a) return 0;

    return 1 + max(height(a->left), height(a->right));
}

Node *newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data  = data; 
    temp->left  = temp->right = NULL; 
    return (temp); 
} 