/**
 * How to invert a bst?  
 * 
 * This can be done iteratively with an external
 * data structure, this is done in O(n) time 
 * 
 * This can be done recursively with stack frames,
 * and this is done in O(n) time, but O(h) stack frames
 * for every single function call.
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int datum;
    TreeNode *left;
    TreeNode *right;
};


TreeNode *invertTreeRecursive(TreeNode *root)
{
    if (!root)
    {
        return NULL;
    }

    swap(root->left, root->right);
    // TreeNode *temp = root->left;
    // root->left = root->right;
    // root->right = temp;

    invertTreeRecursive(root->left);
    invertTreeRecursive(root->right);

    return root;
}

TreeNode* invertTreeIterative(TreeNode* a){
    if(!a) { return a; }

    queue<TreeNode*> tree;

    tree.push(a);

    while(!tree.empty()){
        TreeNode* temp = tree.front();
        swap(temp->left, temp->right);

        if(temp->left){
            tree.push(temp->left);
        }
        if(temp->right){
            tree.push(temp->right);
        }

        tree.pop();
    }

    return a;
}


/////////////////////////////
//      Helper functions   //
/////////////////////////////

// Utility function to create new Node 
TreeNode *newNode(int data) 
{ 
    TreeNode *temp = new TreeNode; 
    temp->datum  = data; 
    temp->left  = temp->right = NULL; 
    return (temp); 
} 


void printLevelOrder(TreeNode *root){

    if(!root) { return; }

    deque<TreeNode*> container;
    container.push_back(root);

    while(1){
        int size = container.size();

        if(!container.size()){ break; }

        while(size > 0){
            TreeNode *temp = container.front();
            cout << temp->datum << " ";
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

TreeNode* insert(TreeNode* n, int a){
    if (n == NULL){ return newNode(a); }

    if (n->datum < a){
        n->right = insert(n->right, a);
    }
    else if(n->datum > a){
        n->left = insert(n->left, a);
    }

    return n;
}


int main()
{
    TreeNode *root2   = NULL;
    root2 = insert(root2, 3);
    insert(root2, 8);
    insert(root2, 10);
    insert(root2, 15);
    insert(root2, -1);
    insert(root2, 13);
    insert(root2, 11);
    insert(root2, -3);
    insert(root2, 7);
    insert(root2, 3);
    insert(root2, 4);
    insert(root2, 6);
    insert(root2, 14);
    insert(root2, 5);
    insert(root2, 2);
    insert(root2, -7);
    insert(root2, 12);
     insert(root2, -4);
    insert(root2, -5);
    insert(root2, 9);
    insert(root2, 16);
    insert(root2, 18);
    insert(root2, 19);
    insert(root2, 17);

    std::cout << "Printing tree " << endl;
    printLevelOrder(root2);

    std::cout << "Printing tree reversal " << endl;
    root2 = invertTreeIterative(root2);
    printLevelOrder(root2);

    std::cout << "Printing tree " << endl;
    root2 = invertTreeRecursive(root2);
    printLevelOrder(root2);

    return 0;
}