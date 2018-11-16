/**
 * 
 *  Nathan Zhu October 22th, 2018 1:31pm at Starbucks on State Street
 *  Rotating a linked list
 * 
 *  https://www.geeksforgeeks.org/rotate-a-linked-list/
 * 
 *  Neil and Renying have the first 484 exam today.  I am figuring out how to shift a linked list
 *   
 *  The problem is 
 * 
 *  1 -> 2 -> 3 -> 4 -> 5 -> NULL
 * 
 *  rotate(3)
 * 
 *  4 -> 5 -> 1 -> 2 -> 3 -> NULL
 * 
 *  We create a circular linked list, and simply change the head pointer
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

    void rotate(int n){

        //Getting a pointer to end of list
        Node *last = this->head;
        while(last && last->next){
            last = last->next;
        }

        //making list circular
        last->next = this->head;

        //Getting a pointer to new head and new tail
        Node* new_head = head->next;
        Node* new_tail = head;
        for(int i = 0; i < n - 1; ++i){
            new_head = new_head->next;
            new_tail = new_tail->next;
        }

        //Cutting circular linked list
        head = new_head;
        new_tail->next = nullptr;
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

    void print(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    //Should make a linked list with loop of length 3
    //return 3
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    cout << "After shifting by 3, list goes from:" << endl;
    ll.print();
    ll.rotate(3);
    ll.print();
    cout << "List is same again:" << endl;
    ll.rotate(2);
    ll.print();
    ll.rotate(18);
    ll.print();
    cout << "Rotate list by 18, should be same as rotating by 3" << endl;

    //Should make a linked list with length of 1
    //return 0
    LinkedList ll2;
    cout << "Rotate a list of size 1 by 18" << endl;
    ll2.push(20);
    ll2.print();
    ll2.rotate(18);
    ll2.print();

    return 0;
}