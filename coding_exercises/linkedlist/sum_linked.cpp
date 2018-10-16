#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insert(ListNode *root, int val);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *a = l1;
    ListNode *b = l2;
    ListNode *returned = NULL;

    int overflow = 0;

    while (a && b)
    {
        int temp = a->val + b->val + overflow;

        if (temp >= 10)
        {
            overflow = 1;
            returned = insert(returned, temp - 10);
        }
        else
        {
            overflow = 0;
            returned = insert(returned, temp);
        }
        a = a->next;
        b = b->next;
    }

    while (a)
    {
        int temp = a->val + overflow;

        if (temp >= 10)
        {
            overflow = 1;
            returned = insert(returned, temp - 10);
        }
        else
        {
            overflow = 0;
            returned = insert(returned, temp);
        }
        a = a->next;
    }
    while (b)
    {
        int temp = b->val + overflow;

        if (temp >= 10)
        {
            overflow = 1;
            returned = insert(returned, temp - 10);
        }
        else
        {
            overflow = 0;
            returned = insert(returned, temp);
        }
        b = b->next;
    }


    if (overflow){
        returned = insert(returned, 1);
    }

    return returned;
}



void print(ListNode* n){
    if(!n) return;

    cout << n->val << " ";

    print(n->next);
}

int main()
{
    ListNode *root = NULL;
    root = insert(root,9);
    root = insert(root,3);
    root = insert(root,5);
    root = insert(root,9);
    root = insert(root,9);
    root = insert(root,9);
    print(root);
    cout << endl;

    ListNode *root2 = NULL;
    root2 = insert(root2,4);
    root2 = insert(root2,5);
    root2 = insert(root2,6);
    print(root2);
    cout << endl;


    ListNode *sum = addTwoNumbers(root, root2);
    print(sum);
    cout << endl;
}

ListNode *insert(ListNode *root, int val)
{
    ListNode *temp = new ListNode(val);

    if (!root)
    {
        root = temp;
    }
    else
    {
        ListNode *i = root;
        while (i->next)
        {
            i = i->next;
        }
        i->next = temp;
    }

    return root;
}
