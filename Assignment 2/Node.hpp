// This implements a class that represents a node object for two pointer and an item object.
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#include "Node.h"
#include <cstddef>
// default constructor initializes next and prev as null
template <class T>
Node<T>::Node(){
    next = NULL;
    prev = NULL;
}
// specific constructor initializes our item to the value_type reference
template <class T>
Node<T>::Node(T &sentItem){
    item = sentItem;
}
// destructor
template <class T>
Node<T>::~Node(){

}

// modifying the next pointer
template <class T>
void Node<T>::setNext(Node<T>* nextNode){
    next = nextNode;
}
// modifying the prev pointer
template <class T>
void Node<T>::setPrev(Node<T>* prevNode){
    prev = prevNode;
}
// modifying the stored value_type
template <class T>
void Node<T>::setData(T& sentItem){
    item = sentItem;
}

// returning the node pointer to the next node
template <class T>
Node<T>* Node<T>::getNext() const{
    return next;
}
// returning the node pointer to the previous node
template <class T>
Node<T>* Node<T>::getPrev() const{
    return prev;
}

// returning the value_type reference of our stored data
template <class T>
T& Node<T>::getData(){
    return item;
}