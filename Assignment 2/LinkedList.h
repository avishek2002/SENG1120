// This defines a class that represents the Linkedlist class for the node object and three pointers; head, tail and current
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Node.h"
using namespace std;
#include <string>
// templatizing to use T as the type for our stored objects
template <class T>
class LinkedList{
    private:
    // members that are not visible externally
        Node<T>* head;
        Node<T>* tail;
        Node<T>* current;
        int listLength;
    
    public:
    // members visible externally
        // default constructor
        LinkedList();
        // destructor
        ~LinkedList();

        // mutator methods
        void addToHead(T&);
        void addToTail(T&);
        void addToCurrent(T&);
        T removeFromHead() ;
        T removeFromTail() ;
        T removeFromCurrent() ;


        // current pointer manipulation
        void start();
        void end();
        void forward();
        void back();

        // accessor methods
        T& getFromHead() const;
        T& getFromTail() const;
        T& getFromCurrent() const;
        int getSize() const;

        // method to return the elements of the linkedlist
        ostream& print(ostream& out);

    // member operator overload ==
    bool operator == (LinkedList&);
    // member operator overload +=
    void operator += (LinkedList&);
};
// non member operator overload <<
template <class T>
ostream& operator << (ostream&, LinkedList<T>&);
#include "LinkedList.hpp"
#endif