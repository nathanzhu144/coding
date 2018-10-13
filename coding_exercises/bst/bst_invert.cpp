#include <iostream>

struct TreeNode
{
    int datum;
    TreeNode *left;
    TreeNode *right;
};


TreeNode *invertTree(TreeNode *root)
{
    if (!root)
    {
        return NULL;
    }

    TreeNode *temp = root->left;

    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main()
{
    return 0;
}