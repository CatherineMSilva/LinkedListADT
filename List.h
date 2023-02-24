// File : List.h
// Class: COP 3530 Digital Sys & Architecture
// Dev  : Catherine Silva
// Desc : Linked List ADT interface
// --------------------------------------------------------


#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H


const int LIST_HEAD = 0;
const int LIST_TAIL = -1;


class List {
private:

    struct Node {
        int value;
        Node* next;
    };

    Node* head;
    int size;


public:

    List();


    ~List(); //destructor


    int getSize();
    bool isEmpty();


    void insert(int value, int position=LIST_TAIL); //=List_tail is a default value


    int remove(int position=LIST_TAIL);


    int read(int position);


    void modify(int value, int position);

private:

    Node* traverse(int position);


};


#endif //LINKEDLIST_LIST_H