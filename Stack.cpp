#include "Stack.h"

void Stack::push(int value) {
    data.push_back(value);
}

int Stack::pop() {
    if (data.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    int topValue = data.back();
    data.pop_back();
    return topValue;
}

int Stack::top() const {
    if (data.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

bool Stack::isEmpty() const {
    return data.empty();
}

size_t Stack::size() const {
    return data.size();
}

double Stack::average() const {
    if (data.empty()) {
        throw std::out_of_range("Stack is empty");
    }
    double sum = 0;
    for (int num : data) {
        sum += num;
    }
    return sum / data.size();
}
