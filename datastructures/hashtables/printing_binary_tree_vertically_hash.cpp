// C++ program for printing vertical order of a given binary tree
// https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
// Nathan Zhu 5/31/2018 in Dental Building
//
// The purpose of this program is to use a hash table to print a binary tree
// vertically.  Pretty easy.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A utility function to create a new node
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}


//Solution//

void get_vertical_order(Node* root, int distance_from_root, std::map<int, std::vector<int>>& verts){
    if(root == nullptr){
        return;
    }

    //Adds current key to the distance vector
    verts[distance_from_root].push_back(root->key);

    //Looks at left subtree
    get_vertical_order(root->left, distance_from_root - 1, verts);

    //Looks at right subtree
    get_vertical_order(root->right, distance_from_root + 1, verts);
}


void print_vertical_order(Node* root){
    std::map<int, std::vector<int>> verts_in;
    get_vertical_order(root, 0, verts_in);

    std::cout << std::endl;

    for(std::map<int, std::vector<int>>::iterator i = verts_in.begin(); i != verts_in.end(); ++i){
        for(auto &j: (*i).second){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n ";
    print_vertical_order(root);
    return 0;
}
