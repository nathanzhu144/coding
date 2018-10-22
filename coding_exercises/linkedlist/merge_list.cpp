/**
 * 
 *  Nathan Zhu October 22th, 2018 2:03 pm at Starbucks on State Street
 *  Merging a linked list
 * 
 *  https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
 * 
 *  Same as mergesort with arrays, but with linked lists.
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* Link list node */
struct Node
{
    int data;
    struct Node *next;

    //Constructor
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList
{
  public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    ////////////////////////////////////
    //         Helper functions       //
    ////////////////////////////////////

    //Adds a datum to front of linked list
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push_back(int data)
    {
        Node *temp = new Node(data);

        if (!head)
        {
            head = temp;
        }
        else
        {
            Node *last = head;
            while (last->next)
            {
                last = last->next;
            }
            last->next = temp;
        }
    }
};


/////////////////////////////////////////////////////////
//         These are the interesting functions         //
/////////////////////////////////////////////////////////

Node *merge(Node* a, Node* b)
{
    //Checking if left or right linked lists are empty.
    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }

    //Checking whether to start from first or second linked list
    Node *current = nullptr;
    if (a->data < b->data)
    {
        current = a;
        a = a->next;
    }
    else
    {
        current = b;
        b = b->next;
    }
    
    Node* new_head = current;

    //Merging two lists
    while (a || b)
    {
        if (!a){
            current->next = b;
            b = b->next;
            current = current->next;
            continue;
        }
        else if (!b){
            current->next = a;
            a = a->next;
            current = current->next;
        
            continue;
        }

        else if(a->data > b->data){
            current->next = b;
            b = b->next;
             current = current->next;
        }
        else{
            current->next = a;
            a = a->next;
             current = current->next;
        }
    }

    return new_head;
}

void print(Node* a){
    if(!a) { return; }

    cout << a->data << " ";

    print(a->next);
}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    //Should make a linked list with loop of length 3
    //return 3
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(13);
    ll.push_back(15);

    LinkedList ll2;
    ll2.push_back(1);
    ll2.push_back(6);
    ll2.push_back(6);
    ll2.push_back(8);
    ll2.push_back(9);
    ll2.push_back(10);
    ll2.push_back(11);
    ll2.push_back(12);
    ll2.push_back(13);
    ll2.push_back(17);
    ll2.push_back(19);
    ll2.push_back(20);

    cout << "First we have two linked lists" << endl;
    ll.print();
    cout << endl;
    ll2.print();
    cout << endl;
    cout << "The merged result is" << endl;
    Node *merged = merge(ll.head, ll2.head);
    print(merged);

    return 0;
}