#include <iostream>
#include "SLL.h"
using namespace std;

Node::Node(int val) {
    data = val;
    next = NULL;
}

List::List() {
    head = tail = NULL;
}

List::~List() {
    while (head != NULL) {
        pop_front();
    }
}

void List::push_front(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void List::pop_front() {
    if (head == NULL) return;

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void List::push_back(int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::pop_back() {
    if (head == NULL) return;

    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
}

void List::insert(int val, int pos) {
    if (pos < 1) return;

    if (pos == 1) {
        push_front(val);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 2; i++) {
        if (temp == NULL) break;
        temp = temp->next;
    }

    if (temp == NULL) return;

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }
}

void List::pop_specific(int val) {
    if (head == NULL) return;

    if (head->data == val) {
        pop_front();
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    if (temp->next == tail) {
        pop_back();
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void List::reverseList() {
    if (head == NULL) return;

    tail = head;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool List::search(int val) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void List::displayLL() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
