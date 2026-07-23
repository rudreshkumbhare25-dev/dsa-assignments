#ifndef DLL_H
#define DLL_H

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val);
};

class DLL {
    Node* head;
    Node* tail;

public:
    DLL();
    ~DLL();

    void push_front(int val);
    void push_back(int val);
    void insert(int val, int key);
    void pop_front();
    void pop_back();
    void pop_specific(int val);
    void displayDLL();
};

#endif
