#pragma once
#include <iostream>

// Node structure for singly linked list
struct Node {
    int data;       // Data for node
    Node* next;     // Next node pointer

    Node(int value) : data(value), next(nullptr) {}  
};

// Class for the singly linked list
class LinkedList {
private:
    Node* head;     // Head
    Node* tail;     // Tail
    int num_items;  // # of items

public:
    LinkedList();   // Constructor
    ~LinkedList();  // Destructor

    // Functions to modify the list
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    int front() const;
    int back() const;
    bool empty() const;
    void insert(size_t index, int value);
    bool remove(size_t index);
    size_t size() const;
    size_t find(int value) const;
};

