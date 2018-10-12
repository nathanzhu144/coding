#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <iostream>

using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

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
            container.pop_back();

            if(temp->left){
                container.push_front(temp->left);
            }
            if(temp->right){
                container.push_front(temp->right);
            }
        }
        std::cout << std::endl;
    }
}