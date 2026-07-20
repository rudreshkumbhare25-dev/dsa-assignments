#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int val);
};

class List {
    Node* head;
    Node* tail;

public:
    List();
    ~List();

    void push_front(int val);
    void pop_front();
    void push_back(int val);
    void pop_back();
    void insert(int val, int pos);
    void pop_specific(int val);
    void reverseList();
    void search(int val);
    void displayLL();
};

#endif
