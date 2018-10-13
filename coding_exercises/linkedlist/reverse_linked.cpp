/**
 * 
 *  Nathan Zhu October 13th, 2018
 *  Linked list reverse
 *  https://www.geeksforgeeks.org/reverse-a-linked-list/
 *  
 *  Neil and Renying are doing the 484 project 2, and are using a late day,
 *  They do not like 484, I think.
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
};

class LinkedList
{
    public: 
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *next = nullptr;
        Node *current = head;

        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void print()
    {
        for (Node *i = head; i; i = i->next)
        {
            cout << i->data << " ";
        }
        cout << endl;
    }

    void push(int data){
        Node * temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    //ll.reverse();
    ll.print();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
