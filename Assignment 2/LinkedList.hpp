// This implements a class that represents a LinkedList class for the node object and three pointers; head, tail and current
// Programmer : Avishek 3393440
// Last modified : 27/09/22
// Course : SENG1120 Data Structures

#include "LinkedList.h"
#include <iostream>
#include <cstddef>
// default constructor initializes private members to null
template <class T>
LinkedList<T>::LinkedList(){
    listLength = 0;
    head = NULL;
    tail = NULL;
    current = NULL;
}
// destructor for linkedlist
template <class T>
LinkedList<T>::~LinkedList(){
    Node<T> * deleter;
    while(head != NULL){
        deleter = head;
        head = head->getNext();
        delete deleter;
    }
    tail = NULL;
    listLength = 0;
}

// method to add data to head
template <class T>
void LinkedList<T>::addToHead(T& item){
    Node<T>* node = new Node<T>(item);
    // if there are no nodes, first node is created and head, tail and current point to it
    if (listLength==0){
        head = node;
        head->setNext(NULL);
        head->setPrev(NULL);
        tail = head;
        current = head;
        ++listLength;
    }
    // else point the current head to the new node and the new node points to the head, then change the head pointer
    else if (listLength>0){
        head->setPrev(node);
        node->setNext(head);
        node->setPrev(NULL);
        head = node;
        current = head;
        ++listLength;
    }
}
// method to add data to tail
template <class T>
void LinkedList<T>::addToTail(T& item){
    Node<T>* node = new Node<T>(item);
    // if there are no nodes, first node is created and tail, head and current point to it
    if (listLength==0){
        tail = node;
        tail->setNext(NULL);
        tail->setPrev(NULL);
        head = tail;
        current = tail;
        ++listLength;
    }
    // else point the current tail to the new node and the new node points to the tail, then change the tail pointer
    else if (listLength>0){
        tail->setNext(node);
        node->setPrev(tail);
        node->setNext(NULL);
        tail = node;
        ++listLength;
    }
}
// method to add data to current
template <class T>
void LinkedList<T>::addToCurrent(T& item){
    Node<T>* node = new Node<T>(item);
    // if there are no node, first node is created and current, head and tail point to it
    if (listLength==0){
        current = node;
        current->setNext(NULL);
        current->setPrev(NULL);
        head = current;
        tail = current;
        ++listLength;
    }
    // if there are some nodes and there is a node ahead of current, point the new nodes previous pointer to current nodes previous and the new nodees next pointer to the current node. Also, point the current nodes previous nodes next node to the new node and current nodes previous node to the new node.
    else if (current->getPrev() != NULL){
        node->setPrev(current->getPrev());
        node->setNext(current);
        current->getPrev()->setNext(node);
        current->setPrev(node);
        current = node;
        ++listLength;
    }
    // if there is no node ahed of current, point the new nodes next node to current node and the current nodes previous node to the new node Also, set the new nodes previous node to null.
    else if (current->getPrev() == NULL){
        node->setNext(current);
        current->setPrev(node);
        node->setPrev(NULL);
        current = node;
        head = current;
        ++listLength;
    }
}
// method to remove data from head and return the data stored in it
template <class T>
T LinkedList<T>::removeFromHead(){
    // retrieve the data so that we dont lose it
    T item = head->getData();
    Node<T>* temp = head;
    head = head->getNext();
    // since the head will be deleted, if the next node is null, then the linked list will be empty otherwise the previous node of the new head node points to null
    if (head != NULL){
        head->setPrev(NULL); 
    } 
    else{
        tail = NULL; 
    }
    delete temp;
    current = head;
    --listLength;
    return item;
}
// method to remove data from tail and return the data stored in it
template <class T>
T LinkedList<T>::removeFromTail(){
    T item = tail->getData();
    Node<T>* temp = tail;
    tail = tail->getPrev();
    // since the tail will be deleted, if the previous node is null, then the linked list will be empty otherwise the next node of the new tal node points to null
    if (tail != NULL){
        tail->setNext(NULL);
    }
    else{
        head = NULL;
    }
    delete temp;
    current = head;
    --listLength;
    return item;
}
// method to remove data from current and return the data stored in it
template <class T>
T LinkedList<T>::removeFromCurrent(){
    T item = current->getData();
    Node<T>* temp = current;
    if (current->getPrev() != NULL){
        if (current->getNext() != NULL){
            // the previous and the next nodes from the current node are not null, the current nodes previous node points its next node to current nodes next node, and the current nodes next node points its previous node to current nodes previous node
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
        }
        else{
            // the previous node is not null but the next node is null meaning that it is at the tail, the current nodes previous node points its next node to null
            current->getPrev()->setNext(NULL);
            tail = current->getPrev();
        }
    }
    else{
        if (current->getNext() != NULL){
            // the previous node is null but the next node is not null meaning that it is at the head, the current nodes next node points its previous node to null 
            current->getNext()->setPrev(NULL);
            head = current->getNext();
        }
        else{
            // the previous and the next nodes are null meaning the linkedlist is empty
            head = NULL;
            tail = NULL;
        }
    }
    delete temp;
    current = head;
    --listLength;
    return item;
}

// methods to move current pointer
template <class T>
void LinkedList<T>::start(){ 
    // point the current to the head
    current = head;
}
template <class T>
void LinkedList<T>::end(){
    // point the current to the tail
    current = tail;
}
template <class T>
void LinkedList<T>::forward(){
    // move the current pointer to the next node
    if (current != NULL){
        current = current->getNext();
    }
}
template <class T>
void LinkedList<T>::back(){
    // move the current pointer to the previous node
    if (current != NULL){
        current = current->getPrev();
    }
}

// method to get data from head as value_type reference
template <class T>
T&  LinkedList<T>::getFromHead() const{
    // return the data stored in the node pointed by the head pointer
    if (head != NULL){
            return head->getData();
    }
    throw runtime_error("Head is null!");
}
// method to get data from tail as value_type reference
template <class T>
T&  LinkedList<T>::getFromTail() const{
    // return the data stored in the node pointed by the tail pointer
    if (tail != NULL){
        return tail->getData();
    }
    throw runtime_error("Tail is null!");
}
// method to get data from current as value_type reference
template <class T>
T&  LinkedList<T>::getFromCurrent() const{
    // return the data stored in the node pointed by the current pointer
    if (current != NULL){
        return current->getData();
    }
    throw runtime_error("Current is null!");
}
// method to get the size of the linkedlist as an integer
template <class T>
int LinkedList<T>::getSize() const{
    // return the length (number of nodes) of the list
    return listLength;
}

// overloaded the == operator to check if the two lists are equal or not by traversing through them and checking the values stored in them
template <class T>
bool LinkedList<T>::operator == (LinkedList& toCheck){
    // setting the condition as true
    bool condition = true;
    // if the size of the two linkedlists is not equal then the lists are also not equal
    if (this->getSize() != toCheck.getSize()){
        condition = false;
    }
    else{
        // using the for loop to iterate through each node and check if the values stored at them are equal or not
        for (int i = 0; i<this->getSize(); i++){
            if (this->getFromCurrent().get_name() != toCheck.getFromCurrent().get_name() || this->getFromCurrent().get_score() != toCheck.getFromCurrent().get_score()){
                condition = false;
                break;
            }
            else{
                // if the if statement was false, moving the current pointers of the two lists to the next pointer
                this->forward();
                toCheck.forward();
            }
        }
    }
    return condition;
}
// overloading the += operator to append each node of the parameterized linkedlist to the tail of the initial linkedlist, by traversing through the parameterized linkedlist
template <class T>
void LinkedList<T>::operator += (LinkedList& endPart){
    // iterating through the list to append each of its object to the end of the prior list
    for (int i = 0; i<endPart.getSize(); i++){
        this->addToTail(endPart.getFromCurrent());
        endPart.forward();
    }
    this->start();
    endPart.start();
}

// method that returns the linkedlist data
template <class T>
ostream& LinkedList<T>::print(ostream& out){
    Node<T>* pointer = head;
    for (int i = 0; i<getSize(); i++){
        out << pointer->getData() << " ";
        pointer = pointer->getNext();        
    }
    return out;
}
// overloading the << operator to return an object of ostream& type which consists of the data from each node of the parameterized linkedlist
template <class T>
ostream& operator << (ostream& out, LinkedList<T>& list){
    list.print(out);
    return out; 
}