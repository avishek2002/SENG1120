// This defines a class that represents a queue object for linkedlist object.
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#ifndef _QUEUE
#define _QUEUE
#include "LinkedList.h"
// templatizing to use T as the type for our stored objects
template <class T>
class LQueue{
    private:
	// members that are not visible externally
        LinkedList<T> list;
        int size;

    public:
	// members visible externally
        // default constructor
        LQueue();
		// destrutor
        ~LQueue();

        // mutator methods
        T dequeue();
        void enqueue(T);
		
		// accessor methods
		T& front() const;
        int getSize() const;
        bool isEmpty() const;
		
		// method to return the elements of the queue
        ostream& print(ostream& out);
};
// non member operator overload <<
template <class T>
ostream& operator << (ostream&, LQueue<T>&);
#include "LQueue.hpp"
#endif