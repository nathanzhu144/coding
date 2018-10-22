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

    //Faster pointer and slower pointer, will 
    //meet eventually.
    bool check_for_loop2(){
        Node *slow = this->head;
        Node *fast = this->head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){ return true; }
        }

        return false;
    }

    // Gave up on this right now
    // Shouldn't be too hard with a hash table, but without additional
    // O(n) memory should be possible

    // bool remove_loop(){
    //     Node *slow = this->head;
    //     Node *fast = this->head;
    //     bool flag = false;

    //     //Finding node in loop
    //     while(fast != slow && flag){
    //         flag = true;
    //         slow = slow->next;
    //         fast = fast->next->next;

    //         //If no loop, return false
    //         if(!fast->next) { return false; }
    //     }

    //     //Counting length of loop
    //     Node *node_in_loop = slow;
    //     int loop_length = 0;
    //     while (slow != node_in_loop){
    //         slow = slow->next;
    //         ++loop_length;
    //     }

    //     //Advancing faster by loop length nodes from head
    //     Node* slower = this->head;
    //     Node* faster = this->head;
    //     for(int i = 0; i < loop_length; ++i){
    //         faster = faster->next;
    //     }

    //     //If we start faster pointer by loop length nodes out
    //     //They will meet at beginning of loop.
    //     while(faster != slower){
    //         faster = faster->next;
    //         slower = slower->next;
    //     }

    //     faster->next = nullptr;

    //     return true;
    //}



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
    cout << "This list should have loop, : " << ll.check_for_loop2() << endl;
    cout << "This list has loop of length: " << ll.find_loop_length() << endl;

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