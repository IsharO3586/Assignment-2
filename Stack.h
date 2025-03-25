#pragma once
#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> data;  // Vector to store the stack elements

public:
    void push(int value);   // Add
    int pop();              // remove and returns it
    int top() const;        // return
    bool isEmpty() const;   // Returns true if the stack is empty
    size_t size() const;    // Returns # of elements in the stack
    double average() const; // average of the stack elements
};
