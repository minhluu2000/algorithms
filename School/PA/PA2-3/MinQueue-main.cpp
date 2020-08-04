#include "MinQueue.h"

int main() {

    // Make queue
    cout << "Make queue: ";
    MinQueue<int>* queue = new MinQueue<int>();
    cout << queue->check_queue() << endl;
    
    // Test enqueue
    cout << "Test enqueue: " << endl;
    for (int i = 1; i < 10; ++i) {
        queue->enqueue(i);
        cout << queue->check_queue();
    }
    queue->enqueue(0);
    cout << queue->check_queue();

    // Test min
    cout << "Test min: " << queue->min() << endl;

    // Test size
    cout << "Test size: " << queue->queue_size() << endl;

    // Test dequeue
    cout << "Test dequeue: " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << queue->check_queue();
        queue->dequeue();
    }
    cout << queue->check_queue();
    cout << "\nTest dequeue when queue is empty: " << endl;
    queue->dequeue();
    cout << queue->check_queue() << endl;

    // Test destructor
    cout << "Test destructor: " << endl;
    delete queue;
    

    cout << "Everything works!" << endl;

    return 0;
}
