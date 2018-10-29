

/**
 *  https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *  Nathan Zhu
 *  
 *  Monday October 29nd, 2018
 *  12:04 am, figuring it out one step at a time.
 */

#include <iostream>
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

    Node(){
        this->data = 0;
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

    //////////////////////////////////////
    //         Helper functions         //
    //////////////////////////////////////

    //Prints the linked list
    void print()
    {
        for (Node *i = head; i; i = i->next)
        {
            cout << i->data << " ";
        }
        cout << endl;
    }

    //Adds a datum to front of linked list
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
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

Node *removeNthFromEnd(Node *head, int n)
{
    //If null or n is 0, return head
    if (!head || n == 0)
    {
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;
    Node *previous = head;

    while (n--)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    //Edge case if we delete head
    if (slow == head)
    {
        Node *new_head = head->next;
        delete head;
        return new_head;
    }

    //  A ->  B  ->  C  ->  D  ->  E
    //        ^prev  ^remove
    //
    //  A ->  B  ->  D  ->  E
    //        ^prev
    // 
    while (previous->next != slow)
    {
        previous = previous->next;
    }

    previous->next = previous->next->next;
    delete slow;

    return head;
}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    cout << "Removing 2nd from end" << endl;
    removeNthFromEnd(ll.head, 2);
    ll.print();


    return 0;
}

