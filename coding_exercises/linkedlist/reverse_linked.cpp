/**
 * 
 *  Nathan Zhu October 13th, 2018
 *  Linked list reverse
 *  https://www.geeksforgeeks.org/reverse-a-linked-list/
 *  
 *  Good video on simple recursive:
 *  https://www.youtube.com/watch?v=MRe3UsRadKw
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

    /////////////////////////////////////////////////////////
    //         These are the interesting functions         //
    /////////////////////////////////////////////////////////

    //Reverses the linked list iteratively with 3 pointers
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

    //Recursively reverses a linked list
    void reverse_recusive(Node *node){
        if(!node) { return; }

        if(!node->next){
            head = node;
            return;
        }

        reverse_recusive(node->next);
        node->next->next = node;
        node->next = nullptr;
    }

    //Prints the linked list
    void print()
    {
        for (Node *i = head; i; i = i->next)
        {
            cout << i->data << " ";
        }
        cout << endl;
    }

    //Prints the linked list in reverse
    void reverse_print(){
        reverse_print_helper(head);
        cout << endl;
    }

    void reverse_print_helper(Node *node){
        if(!node){ return; }

        reverse_print_helper(node->next);

        cout << node->data << " ";
    }

    //Adds a datum to front of linked list
    void push(int data)
    {
        Node *temp = new Node(data);
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

    cout << "Printing the reverse list\n";
    ll.reverse_print();

    ll.reverse();
    cout << "\nReversed Linked list \n";
    ll.print();


    return 0;
}