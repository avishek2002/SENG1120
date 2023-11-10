// This implements a class that represents a queue object for linkedlist object.
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#include "LQueue.h"
#include <iostream>
// constructor for queue
template <class T>
LQueue<T>::LQueue(){
    size = 0;
}
// destructor for queue
template <class T>
LQueue<T>::~LQueue(){
	size = 0;
}
// returns the object at the head of the queue if the queue is not empty, and throws runtime error if queue is empty
template <class T>
T LQueue<T>::dequeue(){
    if (list.getSize() != 0){
        size--;
        return list.removeFromHead();
    }
    throw runtime_error("Queue is empty!");
}
// adds the parameterized object at the tail of the queue
template <class T>
void LQueue<T>::enqueue(T item){
    list.addToTail(item);
    size++;
}
// returns the reference to the object at the head of the queue if the queue is not empty, else throws runtime error
template <class T>
T& LQueue<T>::front() const{
    if (list.getSize() != 0){
        return list.getFromHead();
    }
    throw runtime_error("Queue is empty!");
}
// returns the size of the queue, which is stored as the variable size
template <class T>
int LQueue<T>::getSize() const{
    return size;
}
// returns the boolean value after checking if the queue is empty or not
template <class T>
bool LQueue<T>::isEmpty() const{
    if (size==0){
        return true;
    }
    else {
        return false;
    }
}
// returns an ostream reference type, which stores the data of the queue, if queue is empty it returns corresponding message
template <class T>
ostream& LQueue<T>::print(ostream& out){
    if (size==0){
        out << "Queue is empty!";
    }
    else {
        out << list;
    }
    return out;
}
// overloading the << operator to return an object of ostream& type which consists of the data from the queue
template <class T>
ostream& operator << (ostream& out, LQueue<T>& queue){
    queue.print(out);
    return out;
}
