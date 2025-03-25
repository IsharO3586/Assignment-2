#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// Check if the list is empty
bool LinkedList::empty() const {
    return num_items == 0;
}


// add new element at beginning 
void LinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    num_items++;
}

// add end of list
void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}


// remove first element
void LinkedList::pop_front() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    num_items--;
}


// remove last element
void LinkedList::pop_back() {
    if (head == nullptr) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// Get value at the front
int LinkedList::front() const {
    if (head != nullptr) {
        return head->data;
    }
    throw std::out_of_range("List is empty");
}

// Get value at the back
int LinkedList::back() const {
    if (tail != nullptr) {
        return tail->data;
    }
    throw std::out_of_range("List is empty");
}

// Insert a value at a specific index
void LinkedList::insert(size_t index, int value) {
    if (index == 0) {
        push_front(value);
        return;
    }
    Node* current = head;
    for (size_t i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == nullptr) {
        tail = newNode;
    }
    num_items++;
}

// Remove an element at a specific index
bool LinkedList::remove(size_t index) {
    if (index == 0) {
        pop_front();
        return true;
    }
    Node* current = head;
    for (size_t i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        return false;
    }
    Node* toDelete = current->next;
    current->next = toDelete->next;
    if (toDelete == tail) {
        tail = current;
    }
    delete toDelete;
    num_items--;
    return true;
}

// Find the index of a value
size_t LinkedList::find(int value) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items; // Not found
}

// Return the size of the list
size_t LinkedList::size() const {
    return num_items;
}