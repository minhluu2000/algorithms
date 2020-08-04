#ifndef STACK_H
#define STACK_H

#define MAX 1000

class Stack {
    int top;
    public:
        int a[MAX];
        Stack() { top = -1; };
        bool push(int);
        int pop();
        int peek();
        bool isEmpty();
};


#endif