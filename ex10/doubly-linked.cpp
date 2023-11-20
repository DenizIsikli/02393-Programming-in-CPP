#include "doubly-linked.h"
#include <vector>

List::List(void) {
    first = nullptr;
}

List::~List(void) {
    Node *current = first;

    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void List::insert(int n) {
    if (first == nullptr) {
        first = new Node;
        first->val = n;
        first->next = nullptr;
        first->prev = nullptr;
    } else {
        Node *current = first;

        while (current->next != nullptr) {
            current = current->next;
        }

        Node *newNode = new Node;
        newNode->val = n;
        newNode->next = nullptr;
        newNode->prev = current;
        current->next = newNode;
    }
}

void List::reverse(void) {
    Node *current = first;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    first = prev;
}

void List::print(void) {
    Node *current = first;

    while (current != nullptr) {
        cout << current->val << " ";

        if (current->next == nullptr) {
            cout << endl;
        }
        current = current->next;
    }
}
