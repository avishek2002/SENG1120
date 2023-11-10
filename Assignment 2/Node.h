// This defines a class that represents a node object for two pointers and an item object.
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#ifndef _NODE
#define _NODE
// templatizing to use T as the type for our stored objects
template <class T>
class Node{
    public :
    // Members that are externally visible
        // default constructor
        Node();
        // parameterized/specific constructor
        Node(T&);
        // desctructor
        ~Node();

        // mutator methods
        void setNext(Node*);
        void setPrev(Node*);
        void setData(T&);

        // accessor methods
        Node* getNext() const;
        Node* getPrev() const;
        T& getData();

    private:
    // Members that aren't visible externally
        Node* prev;
        Node* next;
        T item;
};
#include "Node.hpp"
#endif