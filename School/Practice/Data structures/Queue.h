#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue {
    int capacity; // actual length of queue array
    int* array;  // the queue array
    int front, back; // index of the first and last object
    int count; // number of elements

    public:
        Queue(int);
        Queue(const Queue&);
        Queue& operator=(const Queue&);
        ~Queue();
        bool isEmpty() const;
        int first();
        int last();
        void enqueue(const int);
        int dequeue();
        int size() const;
};



#endif