// This implements a class that represents a stack object for linkedlist object.
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#include "LStack.h"
#include <iostream>
// constructor for stack
template <class T>
LStack<T>::LStack(){
    size = 0;
}
// destructor for stack
template <class T>
LStack<T>::~LStack(){

}
// removes and returns the object at the top of the stack if the stack is not empty, else throws runtime error
template <class T>
T LStack<T>::pop(){
    if (list.getSize() != 0){
        size--;
        return list.removeFromTail();
    }
    throw runtime_error("Stack is empty!");
}
// adds the parameterized object to the top of the stack
template <class T>
void LStack<T>::push(T item){
    list.addToTail(item);
    size++;
}
// returns the reference to the object at the top of the stack if the stack is not empty, else throws runtime error
template <class T>
T& LStack<T>::peek() const{
    if (list.getSize() != 0){
        return list.getFromTail();
    }
    throw runtime_error("Stack is empty!");
}
// returns the size of the stack
template <class T>
int LStack<T>::getSize() const{
    return size;
}
// returns the boolean value after checking if the stack is empty or not
template <class T>
bool LStack<T>::isEmpty() const{
    if (size==0){
        return true;
    }
    else {
        return false;
    }
}
// returns an ostream reference type, which stores the data of the stack, if stack is empty it returns corresponding message
template <class T>
ostream& LStack<T>::print(ostream& out){
    if (size==0){
        out << "Stack is empty!";
    }
    else {
        out << list;
    }
    return out;
}
// overloading the << operator to return an object of ostream& type which consists of the data from the stack
template <class T>
ostream& operator << (ostream& out, LStack<T>& stack){
    stack.print(out);
    return out;
}