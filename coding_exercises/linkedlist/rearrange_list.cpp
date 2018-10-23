/**
 *  https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/
 *  Nathan Zhu
 *  
 *  Monday October 22nd, 2018
 *  4:29 pm, just dropped Renying's phone.  Also, pushed myself onto a filing
 *  cabinet in the BBB.
 * 
 *  Neil and Renying have a 484 exam is 2 hours, and they both seem to not like it
 *  Neil claimed that he would get a 100% on the final.
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

/////////////////////////////////////////////////////////
//                Rearrange in place                   //
/////////////////////////////////////////////////////////

Node *rearrange(Node *head)
{
    Node *slow, *fast;
    slow = fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    //                ^ new_head
    //New head is beginning of where linked list is reversed
    Node *new_head = slow->next;
    slow->next = NULL;

    // 1 -> 2 -> 3 -> NULL   4 -> 5 -> 6 -> NULL
    //                       ^ new_head
    Node *current = new_head;
    Node *prev = NULL;;
    Node *next = NULL;

    //Revering second half of linked list
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // 1 -> 2 -> 3 -> NULL   6 -> 5 -> 4 -> NULL
    //                       ^ new_head
    new_head = prev;

    // Step 0:
    // 
    // 1 -> 2 -> 3 -> NULL   6 -> 5 -> 4 -> NULL
    // ^first                ^second

    //Step 1:
    //
    //      v first_next
    // 1 -> 2 -> 3 -> NULL  
    //    /                
    // 6    5 -> 4 -> NULL
    //      ^ second_next

    //Step 2:
    //
    //      v first_next
    // 1   2 -> 3 -> NULL  
    // |  /                
    // 6   5 -> 4 -> NULL  
    //     ^second_next

    Node *first, *second;
    first = head;
    second = new_head;

    while(first && second){
        Node *first_next = first->next;
        Node *second_next = second->next;

        //Step 1
        if(first->next){
            second->next = first->next;
        }
        //Step 2
        first->next = second;

        first = first_next;
        second = second_next;
    }
    

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
    cout << "Rearranging list 1" << endl;
    ll.print();
    rearrange(ll.head);
    ll.print();


    LinkedList ll2;
    ll2.push_back(1);
    ll2.push_back(2);
    ll2.push_back(3);
    ll2.push_back(4);
    ll2.push_back(5);
    ll2.push_back(6);
    cout << "Rearranging list 2" << endl;
    ll2.print();
    rearrange(ll2.head);
    ll2.print();

    return 0;
}