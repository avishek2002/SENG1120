// This implements a class that represents a LinkedList class for the node object and three pointers; head, tail and current
// Programmer : Avishek 3393440
// Last modified : 04/0922
// Course : SENG1120 Data Structures

#include "LinkedList.h"
#include <iostream>


// default constructor initializes private memers to null
LinkedList::LinkedList(){
    listLength = 0;
    head = NULL;
    tail = NULL;
    current = NULL;
}
// destructor for linkedlist
LinkedList::~LinkedList(){

}

// method to add data to head
void LinkedList::addToHead(v_t& item){
    Node* node = new Node(item);
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
void LinkedList::addToTail(v_t& item){
    Node* node = new Node(item);
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
void LinkedList::addToCurrent(v_t& item){
    Node* node = new Node(item);
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
Node::v_t LinkedList::removeFromHead(){
    // retrieve the data so that we dont lose it
    v_t &item = head->getData();
    Node* temp = head;
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
Node::v_t LinkedList::removeFromTail(){
    v_t &item = tail->getData();
    Node* temp = tail;
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
Node::v_t LinkedList::removeFromCurrent(){
    v_t &item = current->getData();
    Node* temp = current;
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
// method to remove data from the linkedlist where the argument name matches the name in the value_type object and returns it
Node::v_t LinkedList::remove(const string name){
    // since there could be more than a single node with "name", traverse through the list the number of times name repeats
    // but the caveat to this is, that we need to return Student (item) type so if there are many items, only the last will be returned
    v_t item;
    int repetition = count(name);
    for (int i = 0; i<repetition; i++){
        // setting current to head so that we can traverse through the whole linkedlist if an instanced matched
        current = head;
        for (int j = 0; j<listLength; j++){
            if (current->getData().get_name() == name){
                item = this->removeFromCurrent();
                // exit from the second loop if name matches
                break;
            }
            else {
                // moving the current pointer forward if the name didn't match
                this->forward();
            }
        }
    }
    current = head;
    return item;
}

// methods to move current pointer
void LinkedList::start(){ 
    // point the current to the head
    current = head;
}
void LinkedList::end(){
    // point the current to the tail
    current = tail;
}
void LinkedList::forward(){
    // move the current pointer to the next node
    if (current != NULL){
        current = current->getNext();
    }
}
void LinkedList::back(){
    // move the current pointer to the previous node
    if (current != NULL){
        current = current->getPrev();
    }
}

// method to get data from head as value_type reference
Node::v_t&  LinkedList::getFromHead() const{
    // return the data stored in the node pointed by the head pointer
    if (head != NULL){
            return head->getData();
    }
    throw runtime_error("Head is null!");
}
// method to get data from tail as value_type reference
Node::v_t&  LinkedList::getFromTail() const{
    // return the data stored in the node pointed by the tail pointer
    if (tail != NULL){
        return tail->getData();
    }
    throw runtime_error("Tail is null!");
}
// method to get data from current as value_type reference
Node::v_t&  LinkedList::getFromCurrent() const{
    // return the data stored in the node pointed by the current pointer
    if (current != NULL){
        return current->getData();
    }
    throw runtime_error("Current is null!");
}
// method to get the size of the linkedlist as an integer
int LinkedList::getSize() const{
    // return the length (number of nodes) of the list
    return listLength;
}

// returns the average of the linkedlist as double
double LinkedList::calcAverage() {
    // traversing through the linkedlist and calculation total score, which is used to determine returned the average 
    current = head;
    double total = 0;
    for (int i = 0; i<listLength; i++){
        // summing up the score of stored by value_type in current
        total += current->getData().get_score();
        current = current->getNext();
    }
    current = head;
    double averageScore = total/listLength;
    return averageScore;
}
// returns the number of occurences of value_type where argumented name matches the name of the value_type
int LinkedList::count(string name){
    // traversing through the linkedlist and incrementing the value of count by 1 for each node that belongs to "name"
    current = head;
    int count = 0;
    for (int i = 0; i<listLength; i++){
        if (current->getData().get_name() == name){
            ++count;
        }
        this->forward();
    }
    current = head;
    return count;
}

// overloaded the == operator to check if the two lists are equal or not by traversing through them and checking the values stored in them
bool LinkedList::operator == (LinkedList& toCheck){
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
void LinkedList::operator += (LinkedList& endPart){
    // iterating through the list to append each of its object to the end of the prior list
    for (int i = 0; i<endPart.getSize(); i++){
        this->addToTail(endPart.getFromCurrent());
        endPart.forward();
    }
    this->start();
    endPart.start();
}
// overloading the << operator to return an object of ostream& type which consists of the data from each node of the parameterized linkedlist
ostream& operator << (ostream& out,  LinkedList& list){ 
    LinkedList workingList = list;
    workingList.start();
    for (int i = 0; i<workingList.getSize(); i++){
        out << workingList.getFromCurrent() << " ";
        workingList.forward();
    }
    workingList.start();
    return out; 
}

void LinkedList::insertionSort(){
    current = head;
    Node* temp;
    Node* key;
    for (int i = 1; i<listLength; i++){
        temp = current;
        key = temp->getNext();
        for (int j = 0; j<i; j++){
            if (key->getData().get_score() < temp->getData().get_score()){
                if (temp->getPrev() != NULL){
                    if (key->getData().get_score() < temp->getPrev()->getData().get_score()){
                        temp = temp->getPrev();
                    }
                    else {
                        if (key->getNext() != NULL){
                            key->getPrev()->setNext(key->getNext());
                            key->getNext()->setPrev(key->getPrev());
                        }
                        else{
                            key->getPrev()->setNext(NULL);
                        }
                        temp->getPrev()->setNext(key);
                        key->setPrev(temp->getPrev());
                        key->setNext(temp);
                        temp->setPrev(key);
                        back();
                        break;
                    }
                }
                else {

                    if (key->getNext() != NULL){
                        key->getPrev()->setNext(key->getNext());
                        key->getNext()->setPrev(key->getPrev());
                    }
                    else{
                        key->getPrev()->setNext(NULL);
                    }
                    temp->setPrev(key);
                    key->setNext(temp);
                    key->setPrev(NULL);
                    head = key;
                    back();
                    break;
                }
            }
        }
        forward();
    }
    current = head;
}

void LinkedList::mergeSortCaller(){
    mergeSort(head);
    while(head->getPrev()!= NULL){
        head = head->getPrev();
    }
}
Node* LinkedList::mergeSort(Node* head){
    if (head == NULL || head->getNext() == NULL){
        return head;
    }
    Node* midNode = split(head);
    head = mergeSort(head);
    midNode = mergeSort(midNode);
    return merge(head, midNode);
}
Node* LinkedList::merge(Node* first, Node* second){
    if (first == NULL){
        return second;
    }
    if (second == NULL){
        return first;
    }

    if (first->getData().get_score() < second->getData().get_score()){
        first->setNext(merge(first->getNext(),second));
        first->getNext()->setPrev(first);
        first->setPrev(NULL);
        return first;
    }
    else{
        second->setNext(merge(first,second->getNext()));
        second->getNext()->setPrev(second);
        second->setPrev(NULL);
        return second;
    }
}
Node* LinkedList::split(Node* head){
    Node* fast = head;
    Node* slow = head;
    while (fast->getNext() != NULL && fast->getNext()->getNext() != NULL){
        fast = fast->getNext()->getNext();
        slow = slow->getNext();
    }
    Node* mid = slow->getNext();
    slow->getNext()->setPrev(NULL);
    slow->setNext(NULL);
    return mid;
}