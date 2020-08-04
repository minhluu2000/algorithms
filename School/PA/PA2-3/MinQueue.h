#ifndef MINQUEUE_H
#define MINQUEUE_H

#include "TemplatedDLList.h"

template<typename T>
class MinQueue {
    private:
        DLList<T>* dll;
        int size;
    public:
        MinQueue() : dll(new DLList<T>()), size(0) {}
        ~MinQueue() { delete dll; cout << "Destructor called." << endl;}
        void enqueue(T);
        void dequeue();
        int queue_size() { return size; }
        int is_empty() { return size==0; }
        T min();
        const DLList<T> check_queue() { return *dll; }
};

template<typename T>
void MinQueue<T>::enqueue(T obj) {
    dll->insert_last(obj);
    ++size;
}

template<typename T>
void MinQueue<T>::dequeue() {
    if (size == 0) {
        //throw an exception here?
        cout << "Queue is empty." << endl;
        return;
    }
    dll->remove_first();
    --size;
}

template<typename T>
T MinQueue<T>::min() {
    if (size == 0) {
        //throw an exception here?
        cout << "Queue is empty." << endl;
        exit(0);
    }
    T smallest = dll->first();
    DLListNode<T>* current = dll->first_node();
    while (current != dll->after_last_node()) {
        if (current->obj < smallest) {
            smallest = current->obj;
        }
        current = current->next;
    }
    return smallest;
}




#endif