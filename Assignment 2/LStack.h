// This defines a class that represents a stack object for linkedlist object.
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#ifndef _STACK
#define _STACK
#include "LinkedList.h"
// templatizing to use T as the type for our stored objects
template <class T>
class LStack{
    private:
	// members that are not visible externally
        LinkedList<T> list;
        int size;

    public:
	// members visible externally
        // default constructor
        LStack();
		// destructor
        ~LStack();

        // mutator methods
        T pop();
        void push(T);
		
		// accessor methods
		T& peek() const;
        int getSize() const;
        bool isEmpty() const;
		
		// method to return the elements of the stack
        ostream& print(ostream& out);
};
// non member operator overload <<
template <class T>
ostream& operator << (ostream&, LStack<T>&);
#include "LStack.hpp"
#endif