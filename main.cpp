#include <iostream>
#include "LinkedList.h"
#include "Stack.h"




int main() {
    // Test the linked list implementation**************

  
    std::cout << "Linked List Tests:" << std::endl;
    LinkedList list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(30);

    std::cout << "After inserts: Front = " << list.front() << ", Back = " << list.back() << std::endl;

    list.pop_front();
    std::cout << "After pop_front: Front = " << list.front() << ", Back = " << list.back() << std::endl;

    list.pop_back();
    std::cout << "After pop_back: Front = " << list.front() << ", Back = " << (list.empty() ? "List is empty" : std::to_string(list.back())) << std::endl;








    // Test the stack implementation***************
    std::cout << "\nStack Tests:" << std::endl;
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; // Should be 30
    std::cout << "Stack size: " << stack.size() << std::endl; // Should be 3
    std::cout << "Average: " << stack.average() << std::endl; // Should be 20

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should be 20

    return 0;
}
