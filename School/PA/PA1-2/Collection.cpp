#include "Collection.h"

// PART 1
Collection::Collection() : array(nullptr), size(0), capacity(0) {}

Collection::Collection(int n) : array(new Stress_ball[n]), size(n), capacity(n) {}

Collection::Collection(const Collection& other): array(nullptr), size(0), capacity(0) {
    size = other.size;
    capacity = other.capacity;
    array = new Stress_ball[capacity];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

Collection& Collection::operator=(const Collection& other) {
    if (this != &other) {
        // Free existing array
        if (array != nullptr) {
            delete[] array;
        }
        
        // Reconstruct current object
        capacity = other.capacity;
        size = other.size;
        array = new Stress_ball[capacity];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

Collection::~Collection() {
    make_empty();
}

// Move constructor
Collection::Collection(Collection&& other): array(nullptr), size(0), capacity(0) {
    size = other.size;
    capacity = other.capacity;
    array = other.array;
    other.size = 0;
    other.capacity = 0;
    other.array = nullptr;
}

// Move assignment operator
Collection& Collection::operator=(Collection&& other) {
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

void Collection::resize() {
    // Make sure to also resize a Collection object with 0 capacity
    if (capacity == 0) {
        capacity = 1;
        array = new Stress_ball[capacity];
    } else {
        capacity *= 2;
        Stress_ball* temp_array = new Stress_ball[capacity];
        for (int i = 0; i < size; ++i) {
            temp_array[i] = array[i];
        }
        delete[] array; 
        array = temp_array;
    }
}

void Collection::insert_item(const Stress_ball& sb) { // Assume the new object is inserted at the end
    if (capacity == size) {
        resize();
    }
    array[size] = sb;
    ++size;
}

bool Collection::contains(const Stress_ball& sb) const {
    for (int i = 0; i < size; ++i) {
        if (array[i] == sb) {
            return true;
        }
    }
    return false;
}

Stress_ball Collection::remove_any_item() {
    if (size == 0) { // Throw exception when array is empty
        throw "The array is empty!";
        exit(0);
    }
    int idx = rand() % size;
    Stress_ball temp = array[idx];
    for (int i = idx; i < size - 1; ++i) { // Shift everything after this item to the left 
        array[i] = array[i + 1];
    }
    --size;
    return temp;
}

void Collection::remove_this_item(const Stress_ball sb) {
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

Stress_ball* Collection::get_array_ref() { return array; }

int Collection::get_size() { return size; }

int Collection::get_capacity() { return capacity; }

void Collection::make_empty() {
    if (array != nullptr) {
        delete[] array;
    }
    size = 0;
    capacity = 0;
}

bool Collection::is_empty() const {
    if (size == 0) {
        return true;
    }
    return false;
}

int Collection::total_items() const { return size; }

int Collection::total_items(Stress_ball_sizes s) const {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].get_size() == s) {
            ++counter;
        }
    }
    return counter;
}

int Collection::total_items(Stress_ball_colors c) const {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i].get_color() == c) {
            ++counter;
        }
    }
    return counter;
}

void Collection::print_items() const {
    if (size == 0) {
        cout << "This collection is empty." << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }
}

Stress_ball& Collection::operator[](int idx) {
    if (idx >= capacity || idx < 0) {
        throw "Array index out of bound, exiting";
        exit(0);
    }
    return array[idx];
}

const Stress_ball& Collection::operator[](int idx) const {
    if (idx >= capacity || idx < 0) {
        throw "Array index out of bound, exiting";
        exit(0);
    }
    return array[idx];
}

// PART 2
void bubble_sort(Collection& c) {
    int counter = 0;
    for (int i = 0; i < c.total_items() - 1; ++i) {
        for (int j = 0; j < c.total_items() - i - 1; ++j) {
            ++counter;
            if (c[j].get_size() > c[j + 1].get_size()) {
                Stress_ball temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    cout << "Number of comparisons: " << counter << endl;
}

void insertion_sort(Collection& c) {
    for (int i = 1; i < c.total_items(); ++i) {
        Stress_ball ball = c[i];
        int j = i - 1;
        while (j >= 0 && c[j].get_size() > ball.get_size()) {
            c[j + 1] = c[j];
            --j;
        }
        c[j + 1] = ball;
    } 
}

void selection_sort(Collection& c) {
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
        Stress_ball temp = c[i];
        c[i] = c[smallest];
        c[smallest] = temp;
    }
    cout << "Number of comparison: " << counter << endl;
}

void counting_sort(Collection& c) {
    
}

Stress_ball_colors str_to_color(string str) {
    if (str == "red") {
        return Stress_ball_colors::red;
    }
    if (str == "blue") {
        return Stress_ball_colors::blue;
    }
    if (str == "yellow") {
        return Stress_ball_colors::yellow;
    }
    if (str == "green") {
        return Stress_ball_colors::green;
    }
}

Stress_ball_sizes str_to_size(string str) { // DOES NOT WORK?
    // cout << str << endl;
    if (str == "small") {
        return Stress_ball_sizes::small;
    }
    if (str == "medium") {
        return Stress_ball_sizes::medium;
    }
    if (str == "large") {
        return Stress_ball_sizes::large;
    }
}

istream& operator>>(istream& is, Collection& c) {
    string color, size;
    if (is.fail()) {
        throw "Error, cannot open file!";
		cin.ignore();
		exit(1);
	}
    while(!is.eof()) {
        is >> color >> size;
        c.insert_item(Stress_ball(str_to_color(color), str_to_size(size)));
    }
}

ostream& operator<<(ostream& os, const Collection& c) {
    if (c.total_items() == 0) {
        os << "This collection is empty." << "\n";
    }
    for (int i = 0; i < c.total_items(); ++i) {
        os << c[i] << "\n";
    }
    return os;
}

Collection make_union(const Collection& c1, const Collection& c2) {
    Collection* c3 = new Collection(c1.total_items() + c2.total_items());
    for (int i = 0; i < c1.total_items(); ++i) {
        c3->get_array_ref()[i] = c1[i];
    }
    for (int i = 0; i < c2.total_items(); ++i) {
        c3->get_array_ref()[i + c1.total_items()] = c2[i]; 
    }
    return *c3;
}

void cswap(Collection& c1, Collection& c2) { // I renamed from swap to cswap to prevent confusion with the built-in swap function
    Collection temp = move(c1);
    c1 = move(c2);
    c2 = move(temp);
}

void sort_by_size(Collection& c, Sort_choice choice) {
    switch(choice) {
        case Sort_choice::bubble_sort: bubble_sort(c); break;
        case Sort_choice::insertion_sort: insertion_sort(c); break;
        case Sort_choice::selection_sort: selection_sort(c); break;
    }
}
