#include "Queue.h"

Queue::Queue(int cap = 1) : capacity(cap), array(new int[cap]), front(0), back(capacity - 1), count(0) {}

Queue::Queue(const Queue& q) {

}

Queue::~Queue() { delete[] array; }

bool Queue::isEmpty() const { return count == 0; }

int Queue::first() {
    if (isEmpty()) {
        throw ("Access to empty queue");
    }
    return array[front];
}

void Queue::enqueue(const int elem) {
    if (count == capacity) {
        throw "Queue overflow";
    }
    back = (back + 1) % capacity;
    array[back] = elem;
    ++count;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw "Access to empty queue";
    }
    --count;
    int item = array[front];
    front = (front + 1) % capacity;
    return item;
}

// Skip copy constructor and copy assignment operator for now
int Queue::size() const { return count; }

int main() {

}