// This defines a class that represents a node object for two pointers and an item object.
// Programmer : Avishek 3393440
// Last modified : 04/09/22
// Course : SENG1120 Data Structures

#ifndef _NODE
#define _NODE
#include "Student.h"

class Node{
    public :
    // Members that are externally visible
        // using typedef to set v_t as Account type
        typedef Student v_t;
        // default constructor
        Node();
        // parameterized/specific constructor
        Node(v_t&);
        // desctructor
        ~Node();

        // mutator methods
        void setNext(Node*);
        void setPrev(Node*);
        void setData(v_t&);

        // accessor methods
        Node* getNext() const;
        Node* getPrev() const;
        v_t& getData() ;

    private:
    // Members that aren't visible externally
        Node* prev;
        Node* next;
        v_t item;
};
#endif