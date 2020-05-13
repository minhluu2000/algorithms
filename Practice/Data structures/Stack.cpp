#include <iostream>

#include "Stack.h"
using namespace std;

// Stack using arrays
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    } else {
        a[++top] = x;
        cout << x << " pushed into stack." << endl;
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty" << endl;
        return 0;
    } else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

// Driver
int main() {
    Stack* s = new Stack();
    s->push(10);
    s->push(20);
    s->push(30);
    cout << s->pop() << " popped from stack." << endl;
    cout << s->peek() << " peeked from stack." << endl;
}