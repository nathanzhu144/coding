/**
 * 
 *  Nathan Zhu October 22th, 2018 11:21 pm at Starbucks on State Street
 *  Linked list check for loop
 * 
 *  https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
 *  https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/
 *  https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/
 *  Neil and Renying have the first 484 exam today.  I am figuring out how to find a loop in a linked list.
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

    /////////////////////////////////////////////////////////
    //         These are the interesting functions         //
    /////////////////////////////////////////////////////////


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

    void push_back(int data){
        Node *temp = new Node(data);

        if(!head){
            head = temp;
        }
        else{
            Node *last = head;
            while(last->next){
                last = last->next;
            }
            last->next = temp;
        }
    }
};

bool is_palindrome(Node* a){
    if(!a){ return true; }

    Node *middle, *end;
    middle = end = a;

    while(end && end->next){
        end = end->next->next;
        middle = middle->next;
    }



}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    //Should make a linked list with loop of length 3
    //return 3
    LinkedList ll;
    ll.push_back(20);
    ll.push_back(4);
    ll.push_back(15);
    ll.push_back(15);
    ll.push_back(4);
    ll.push_back(20);
    cout << "Should be palindrome " << is_palindrome(ll.head) << endl;

    LinkedList ll;
    ll.push_back(20);


    //Should make a linked list with loop of length 0
    //return 0
    LinkedList ll2;
    ll2.push(20);
    ll2.head->next = ll2.head;
    cout << "This list should have loop, : " << ll2.check_for_loop() << endl;
    cout << "This list should have loop, : " << ll2.check_for_loop2() << endl;
    cout << "This list has loop of length: " << ll2.find_loop_length() << endl;

    //Should make a linked list without a loop
    LinkedList ll3;
    ll3.push_back(20);
    ll3.push_back(4);
    ll3.push_back(15);
    ll3.push_back(85);
    cout << "This list should NOT have loop, : " << ll3.check_for_loop() << endl;
    cout << "This list should NOT have loop, : " << ll3.check_for_loop2() << endl;
    cout << "This list has loop of length: " << ll3.find_loop_length() << endl;

    return 0;
}