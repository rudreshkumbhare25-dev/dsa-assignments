#include <iostream>
#include "DLL.h"
using namespace std;

Node::Node(int val) {
    data = val;
    next = prev = NULL;
}

DLL::DLL() {
    head = tail = NULL;
}

DLL::~DLL() {
    while (head != NULL) {
        pop_front();
    }
}

void DLL::push_front(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DLL::push_back(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DLL::insert(int val, int key) {
    if (head == NULL) return;

    if (head->data == key) {
        push_front(val);
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void DLL::pop_front() {
    if (head == NULL) return;

    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
}

void DLL::pop_back() {
    if (head == NULL) return;

    Node* temp = tail;
    if (head == tail) {                       
        head = tail = NULL;                     
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
}

void DLL::pop_specific(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        pop_front();
        return;
    }

    if (tail->data == val) {
        pop_back();
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void DLL::displayDLL() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}