#ifndef COLLECTION_H
#define COLLECTION_H

#include "Stress_ball.h"
#include "Jeans.h"

// PART 1
template <class Obj, class F1, class F2>
class Collection {
    Obj* array;
    int size;
    int capacity;
    public:
        Collection();
        Collection(int);
        Collection(const Collection<Obj, F1, F2>&);
        Collection<Obj, F1, F2>& operator=(const Collection<Obj, F1, F2>&); // Copy assignment operator
        ~Collection(); // Destructor
        Collection(Collection<Obj, F1, F2>&&); // Move constructor
        Collection<Obj, F1, F2>& operator=(Collection<Obj, F1, F2>&&); // Move assignment operator
        void resize();
        void insert_item(const Obj&);
        bool contains(const Obj&) const;
        Obj remove_any_item();
        void remove_this_item(const Obj);
        void make_empty();
        Obj* get_array_ref();
        int get_size();
        int get_capacity();
        bool is_empty() const;
        int total_items() const;
        int total_items(F2) const;
        int total_items(F1) const;
        void print_items() const;
        Obj& operator[](int);
        const Obj& operator[](int) const;
};

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(): array(nullptr), size(0), capacity(0) {}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(int n) : array(new Obj[n]), size(n), capacity(n) {}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(const Collection<Obj, F1, F2>& other): array(nullptr), size(0), capacity(0) {
    size = other.size;
    capacity = other.capacity;
    array = new Obj[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>::operator=(const Collection<Obj, F1, F2>& other) {
    if (this != &other) {
        // Free existing array
        if (array != nullptr) {
            delete[] array;
        }
        
        // Reconstruct current object
        capacity = other.capacity;
        size = other.size;
        array = new Obj[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::~Collection() {
    make_empty();
}

// Move constructor
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(Collection<Obj, F1, F2>&& other): array(nullptr), size(0), capacity(0) {
    size = other.size;
    capacity = other.capacity;
    array = other.array;
    other.size = 0;
    other.capacity = 0;
    other.array = nullptr;
}

// Move assignment operator
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>& Collection<Obj, F1, F2>::operator=(Collection<Obj, F1, F2>&& other) {
    if (this != &other) {
        delete[] array;

        size = other.size;
        capacity = other.capacity;
        array = other.array;
        other.size = 0;
        other.capacity = 0;
        other.array = nullptr;
    }
    return *this;
}

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::resize() {
    // Make sure to also resize a Collection object with 0 capacity
    if (capacity == 0) {
        capacity = 1;
        array = new Obj[capacity];
    } else {
        capacity *= 2;
        Obj* temp_array = new Obj[capacity];
        for (int i = 0; i < size; ++i) {
            temp_array[i] = array[i];
        }
        delete[] array; 
        array = temp_array;
    }
}

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::insert_item(const Obj& sb) { // Assume the new object is inserted at the end
    if (capacity == size) {
        resize();
    }
    array[size] = sb;
    ++size;
}

template <class Obj, class F1, class F2>
bool Collection<Obj, F1, F2>::contains(const Obj& sb) const {
    for (int i = 0; i < size; ++i) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
}

template <class Obj, class F1, class F2>
Obj Collection<Obj, F1, F2>::remove_any_item() {
    if (size == 0) { // Throw exception when array is empty
        throw "The array is empty!";
        exit(0);
    }
    int idx = rand() % size;
    Obj temp = array[idx];
    for (int i = idx; i < size - 1; ++i) { // Shift everything after this item to the left 
        array[i] = array[i + 1];
    }
    --size;
    return temp;
}

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::remove_this_item(const Obj sb) {
    if (size == 0) { 
        throw "The array is empty!";
        exit(0);
    }
    for (int i = 0; i < size; ++i) {
        if (array[i] == sb) {
            for (int j = i; j < size - 1; ++j) { // Shift everything after this item to the left 
                array[j] = array[j + 1];
            }
            --size;
            return;
        }
    }
}

template <class Obj, class F1, class F2>
Obj* Collection<Obj, F1, F2>::get_array_ref() { return array; }

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::get_size() { return size; }

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::get_capacity() { return capacity; }

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::make_empty() {
    if (array != nullptr) {
        delete[] array;
    }
    size = 0;
    capacity = 0;
}

template <class Obj, class F1, class F2>
bool Collection<Obj, F1, F2>::is_empty() const { return size == 0; }

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items() const { return size; }

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items(F2 s) const {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].get_size() == s) {
            ++counter;
        }
    }
    return counter;
}

template <class Obj, class F1, class F2>
int Collection<Obj, F1, F2>::total_items(F1 c) const {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].get_color() == c) {
            ++counter;
        }
    }
    return counter;
}

template <class Obj, class F1, class F2>
void Collection<Obj, F1, F2>::print_items() const {
    if (size == 0) {
        cout << "This collection is empty." << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }
}

template <class Obj, class F1, class F2>
Obj& Collection<Obj, F1, F2>::operator[](int idx) {
    if (idx >= capacity || idx < 0) {
        throw "Array index out of bound, exiting";
        exit(0);
    }
    return array[idx];
}

template <class Obj, class F1, class F2>
const Obj& Collection<Obj, F1, F2>::operator[](int idx) const {
    if (idx >= capacity || idx < 0) {
        throw "Array index out of bound, exiting";
        exit(0);
    }
    return array[idx];
}

template <class Obj, class F1, class F2>
void bubble_sort(Collection<Obj, F1, F2>& c) {
    int counter = 0;
    for (int i = 0; i < c.total_items() - 1; ++i) {
        for (int j = 0; j < c.total_items() - i - 1; ++j) {
            ++counter;
            if (c[j].get_size() > c[j + 1].get_size()) {
                Obj temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    cout << "Number of comparisons: " << counter << endl;
}

template <class Obj, class F1, class F2>
void insertion_sort(Collection<Obj, F1, F2>& c) {
    for (int i = 1; i < c.total_items(); ++i) {
        Obj ball = c[i];
        int j = i - 1;
        while (j >= 0 && c[j].get_size() > ball.get_size()) {
            c[j + 1] = c[j];
            --j;
        }
        c[j + 1] = ball;
    } 
}

template <class Obj, class F1, class F2>
void selection_sort(Collection<Obj, F1, F2>& c) {
    int counter = 0;
    int smallest;
    for (int i = 0; i < c.total_items() - 1; ++i) {
        smallest = i;
        ++counter;
        for (int j = i + 1; j < c.total_items(); ++j) {
            if (c[smallest].get_size() > c[j].get_size()) {
                smallest = j;
                ++counter;
            }
        }
        Obj temp = c[i];
        c[i] = c[smallest];
        c[smallest] = temp;
    }
    cout << "Number of comparison: " << counter << endl;
}



template <class Obj, class F1, class F2>
ostream& operator<<(ostream& os, const Collection<Obj, F1, F2>& c) {
    if (c.total_items() == 0) {
        os << "This collection is empty." << "\n";
    }
    for (int i = 0; i < c.total_items(); ++i) {
        os << c[i] << "\n";
    }
}

template <class Obj, class F1, class F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2) {
    Collection<Obj, F1, F2>* c3 = new Collection<Obj, F1, F2>(c1.total_items() + c2.total_items());
    for (int i = 0; i < c1.total_items(); ++i) {
        c3->get_array_ref()[i] = c1[i];
    }
    for (int i = 0; i < c2.total_items(); ++i) {
        c3->get_array_ref()[i + c1.total_items()] = c2[i]; 
    }
    return *c3;
}

template <class Obj, class F1, class F2>
void cswap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2) { // I renamed from swap to cswap to prevent confusion with the built-in swap function
    Collection<Obj, F1, F2> temp = move(c1);
    c1 = move(c2);
    c2 = move(temp);
}

enum class Sort_choice {bubble_sort, insertion_sort, selection_sort};

template <class Obj, class F1, class F2> 
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice choice) {
    switch(choice) {
        case Sort_choice::bubble_sort: bubble_sort(c); break;
        case Sort_choice::insertion_sort: insertion_sort(c); break;
        case Sort_choice::selection_sort: selection_sort(c); break;
    }
}


#endif