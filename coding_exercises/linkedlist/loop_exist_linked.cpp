/**
 * 
 *  Nathan Zhu October 22th, 2018 11:21 pm at Starbucks on State Street
 *  Linked list check for loop
 * 
 *  https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
 *  
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

    bool check_for_loop(){
        unordered_set<Node*> address;

        Node *current = this->head;
        while(current){
            //found address
            if(address.find(current) != address.end()){
                return true;
            }

            address.insert(current);
            current = current->next;
        }

        return false;
    }

    int find_loop_length(){
        unordered_map<Node*, int> address;

        Node* current = this->head;
        int node_num = 0;

        while(current){
            if (address.find(current) != address.end()){
                return node_num - address[current];
            }

            address[current] = node_num;
            ++node_num;
            current = current->next;
        }

        return 0;
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
    ll.push_back(20);
    ll.push_back(4);
    ll.push_back(15);
    ll.push_back(85);
    ll.head->next->next->next->next = ll.head->next;
    cout << "This list should have loop, : " << ll.check_for_loop() << endl;
    cout << "This list has loop of length: " << ll.find_loop_length() << endl;

    //Should make a linked list with loop of length 0
    //return 0
    LinkedList ll2;
    ll2.push(20);
    ll2.head->next = ll2.head;
    cout << "This list should have loop, : " << ll2.check_for_loop() << endl;
    cout << "This list has loop of length: " << ll2.find_loop_length() << endl;

    //Should make a linked list without a loop
    LinkedList ll3;
    ll3.push_back(20);
    ll3.push_back(4);
    ll3.push_back(15);
    ll3.push_back(85);
    cout << "This list should NOT have loop, : " << ll3.check_for_loop() << endl;
    cout << "This list has loop of length: " << ll3.find_loop_length() << endl;

    return 0;
}