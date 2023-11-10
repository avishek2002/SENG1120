// This defines a class that represents the Linkedlist class for the node object and three pointers; head, tail and current
// Programmer : Avishek 3393440
// Last modified : 04/09/22
// Course : SENG1120 Data Structures

#ifndef _LINKEDLIST
#define _LINKEDLIST
#include "Node.h"
#include "Student.h"

class LinkedList{
    private:
    // members that are not visible externally
        Node* head;
        Node* tail;
        Node* current;
        int listLength;
    
    public:
    // members visible externally
        typedef Node::v_t v_t;
        // default constructor
        LinkedList();
        // destructor
        ~LinkedList();

        // mutator methods
        void addToHead(v_t&);
        void addToTail(v_t&);
        void addToCurrent(v_t&);
        v_t removeFromHead() ;
        v_t removeFromTail() ;
        v_t removeFromCurrent() ;
        v_t remove(const string) ;

        //insertion sort functions
        void insertionSort();

        //merge sort functions
        void mergeSortCaller();
        Node* mergeSort(Node*);
        Node* merge(Node*, Node*);
        Node* split(Node*);


        // current pointer manipulation
        void start();
        void end();
        void forward();
        void back();

        // accessor methods
        v_t& getFromHead() const;
        v_t& getFromTail() const;
        v_t& getFromCurrent() const;
        int getSize() const;

        // method to calculate average of the scores of the students in the list
        double calcAverage() ;
        // method to calculate number of students
        int count(string);

    // member operator overload ==
    bool operator == (LinkedList&);
    // member operator overload +=
    void operator += (LinkedList&);
};
// non member operator overload <<
ostream& operator << (ostream&,  LinkedList&);
#endif