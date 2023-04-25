// File : List.cpp
// Class: COP 3530 Digital Sys & Architecture
// Dev  : Catherine Silva
// Desc : Linked List ADT implementation
// --------------------------------------------------------
#include "List.h"


/**
 * Default constructor - initialize empty list
 */
List::List() // List:: is scope operator
    : head {nullptr}, size{0} {
} // default constructor


/**
 * Destructor - clean up nodes
 */
List::~List() = default; // destructor


/**
 * Accessor for the list size property
 * @return int size (empty = 0)
 */
int List::getSize() {
    return size;

} // getSize


/**
 * Signifies if the list is empty or not
 * @return bool True if empty (size==0)
 */
bool List::isEmpty() {
    return size == 0;

} // isEmpty


/**
 * Add a new value into the list at the head, a
 * specified position, or at the tail if position
 * is -1 or invalid position
 * @param value - int value to store
 * @param position - position in list to store value (default -1)
 */
void List::insert(int value, int position) {
    Node* temp = new Node{value, nullptr};

    if (position < LIST_HEAD || position >= size)
        position = size;


    // determine where in list to insert
    if (size == 0 || position == LIST_HEAD) {
        temp->next = head; //copying a pointer to a pointer
        head = temp;
    }
    else { //middle or tail of the list
        Node* pNode = head;


        // traversal list to the node -1
        int counter = 0;
        while (counter < position - 1 && pNode->next) {
            pNode = pNode->next;
            counter++;
        } // traversal

        temp->next = pNode->next;
        pNode->next = temp;

    } // where in the list

    // increment size of the list
    size++;

} // insert


/**
 * Remove a value from the list at a specified position and
 * return it to the caller
 * @param position - position in the list or tail if -1
 *                   or invalid position
 * @return - value removed from the list
 */
int List::remove(int position) {
    int value = -1;

    if (position < LIST_HEAD || position >= size) // error check for position existing
        position = size;

    if (isEmpty())
        return value;

    Node* temp;
    if(position == LIST_HEAD) { // remove head
        temp = head;
        head = temp->next;
    }
    else { // remove middle or tail
        if (position == LIST_TAIL)
            position = size - 1;

        Node* pNode = traverse(position - 1);
        temp = pNode->next;
        pNode->next = temp->next; // can also set to pNode->next->next
    } // where are we removing

    value = temp->value;
    delete temp;
    size --; // decrement size after removing a node

    return value;
} // remove


/**
 * Return a value from the list at a specified position without
 * removing it
 * @param position - position in the list
 * @return - value found at position (-1 if not found or invalid position)
 */
int List::read(int position) {
    int value = -1;

    if (size > 0) {
        Node* pNode = traverse(position);
        value = pNode->value;
    }

    return value;

} // read


/**
 * Modify a value at a specified position in the list
 * @param value - new value
 * @param position - position in the list
 */
void List::modify(int value, int position) {
    if (size > 0) {
        Node* pNode = traverse(position);
        pNode->value = value;
    }
} // modify


// private methods
//---------------------------------------------------------

/**
 *
 * @param position
 * @return
 */
List::Node* List::traverse(int position) {
    Node* pNode = head;

    int counter = 0;
    while (counter < position && pNode->next) {
        pNode = pNode->next;
        counter++;
    } // traversal

    return pNode;
}