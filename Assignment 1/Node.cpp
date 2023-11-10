// This implements a class that represents a node object for two pointer and an item object.
// Programmer : Avishek 3393440
// Last modified : 04/09/22
// Course : SENG1120 Data Structures

#include "Node.h"
// default constructor initializes next and prev as null
Node::Node(){
    next = NULL;
    prev = NULL;
}
// specific constructor initializes our item to the value_type reference
Node::Node(Node::v_t &sentItem){
    item = sentItem;
}
// destructor
Node::~Node(){

}

// modifying the next pointer
void Node::setNext(Node* nextNode){
    next = nextNode;
}
// modifying the prev pointer
void Node::setPrev(Node* prevNode){
    prev = prevNode;
}
// modifying the stored value_type
void Node::setData( Node::v_t& sentItem){
    item = sentItem;
}

// returning the node pointer to the next node
Node* Node::getNext() const{
    return next;
}
// returning the node pointer to the previous node
Node* Node::getPrev() const{
    return prev;
}

// returning the value_type reference of our stored data
Node::v_t& Node::getData() {
    return item;
}