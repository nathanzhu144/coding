//This is a doubly linked list implementation with overloads on certain
//functions.

#include <cstddef> //definition for NULL
#include <cassert> //for asserts


template <typename T>
class List
{
  private:
    Node *first;
    Node *last;

    struct Node
    {
        Node *next;
        Node *prev;
        T datum;
    };

  public:
    List() : first(NULL), last(NULL) {}

    bool empty()
    {
        return first == NULL ? true : false;
    }

    void push_back(const &T datum)
    {
        Node *next = new Node;
        next->datum = datum;

        if (empty)
        {
            first = next;
            last = next;
            first->prev = NULL;
            first->next = NULL;
        }
        else
        {
            last->next = next;
            last = next;
        }
    }


};