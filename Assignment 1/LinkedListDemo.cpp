// LinkedListDemo.cpp
// -------------------------------------------------
// This program demonstrates the basic functionality 
// of a linked list that stores student names and 
// scores. It will demo the functions of a basic 
// linked list. The program adds content to a 
// linked list, removes individual nodes, among 
// other functionalities.
// -------------------------------------------------
// Written by SENG1120 Staff: 2009-05-01
// Last update: 2022-08-03 (for sem 2)
// -------------------------------------------------
#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "Student.h"
using namespace std;
void initialize(LinkedList &l1)
{
// populate the first linked list
    Student c("a", 4);
    l1.addToTail(c);
    c.set_score(3);
    l1.addToTail(c);
    c.set_score(2);
    l1.addToTail(c);
    c.set_score(10);
    l1.addToTail(c);
    c.set_score(12);
    l1.addToTail(c);
    c.set_score(1);
    l1.addToTail(c);
    c.set_score(5);
    l1.addToTail(c);
    c.set_score(6);
    l1.addToTail(c);

}
int main(){
    LinkedList firstList;
    initialize(firstList);

    cout << firstList << endl;
    cout << endl << endl;
    //firstList.insertionSort();
    firstList.mergeSortCaller();
    cout << firstList << endl;

cout << "The program has finished." << endl;
return 0;
}