/*
Example code for local unit-testing of HW 4
*/

#include <iostream>
#include <string>
#include "Collection.h"


using CollectionSB = Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes>;
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;

// Overload >> for SB
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

istream& operator>>(istream& is, CollectionSB& c) {
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

// Overload >> for SB
Jeans_colors str_to_jncolor(string str) {
    if (str == "white") {
        return Jeans_colors::white;
    }
    if (str == "blue") {
        return Jeans_colors::blue;
    }
    if (str == "black") {
        return Jeans_colors::black;
    }
    if (str == "brown") {
        return Jeans_colors::brown;
    }
}

Jeans_sizes str_to_jnsize(string str) { // DOES NOT WORK?
    // cout << str << endl;
    if (str == "small") {
        return Jeans_sizes::small;
    }
    if (str == "medium") {
        return Jeans_sizes::medium;
    }
    if (str == "large") {
        return Jeans_sizes::large;
    }
    if (str == "xlarge") {
        return Jeans_sizes::xlarge;
    }
}

istream& operator>>(istream& is, CollectionJN& c) {
    string color, size;
    if (is.fail()) {
        throw "Error, cannot open file!";
		cin.ignore();
		exit(1);
	}
    while(!is.eof()) {
        is >> color >> size;
        c.insert_item(Jeans(str_to_jncolor(color), str_to_jnsize(size)));
    }
}

// Test function
bool sbtest() {

    // Test constructors
    cout << "TEST CONSTRUCTORS:" << endl;
    CollectionSB collection0;
    CollectionSB collection1(10);
    CollectionSB collection2(10);
    CollectionSB collection3(20);
    cout << "\nCollection 0: " << endl;
    collection0.print_items();
    cout << "\nCollection 1: " << endl;
    collection1.print_items();
    cout << "\nCollection 2: " << endl;
    collection2.print_items();

    // Test destructor
    cout << "\nTEST DESTRUCTOR:" << endl;
    CollectionSB* collection4 = new CollectionSB(10);
    CollectionSB* collection5 = new CollectionSB(15);
    delete collection4;
    collection5->make_empty();
    cout << collection5->is_empty() << endl;

    // Test Collection class methods
    cout << "\nTEST RESIZE: " << endl;
    cout << collection2.get_size() << "," << collection2.get_capacity() << endl;
    collection2.resize();
    cout << collection2.get_size() << "," << collection2.get_capacity() << endl;

    // Test inserting large number of items
    cout << "\nTEST INSERTING: " << endl;
    for (int i = 0; i < 20; ++i) {
        collection2.insert_item(Stress_ball());
        cout << "collection2 after "  << i << " insertion: " << collection2.get_size() << "," << collection2.get_capacity() << endl;
    }

    // Test sortings
    cout << "\ncollection2 before bubble sort: " << endl;
    collection2.print_items();
    sort_by_size(collection2, Sort_choice::bubble_sort);
    cout << "\ncollection2 after bubble sort: " << endl;
    collection2.print_items();
    cout << "\ncollection3 before selection sort: " << endl;
    collection3.print_items();
    sort_by_size(collection3, Sort_choice::selection_sort);
    cout << "\ncollection3 after selection sort: " << endl;
    collection3.print_items();
    cout << "\ncollection1 before insertion sort: " << endl;
    collection1.print_items();
    sort_by_size(collection1, Sort_choice::insertion_sort);
    cout << "\ncollection1 after insertion sort: " << endl;
    collection1.print_items();

    // Test additional functions:
    cout << "\nTEST MAKE A UNION: " << endl;
    cout << "Make a union of collection1 and collection3: " << endl;
    CollectionSB collection6 = make_union(collection1, collection3);
    collection6.print_items();

    cout << "\nTEST SWAP: " << endl;
    cout << "Swap collection1 and collection3: " << endl;
    cout << "collection1 and 3, respectively, before swapping: " << endl;
    collection1.print_items();
    cout << endl;
    collection3.print_items();
    cswap(collection1, collection3);
    cout << endl;
    cout << "collection1 and 3 respectively after swapping" << endl;
    collection1.print_items();
    cout << endl;
    collection3.print_items();


    // TEST READ FILE
    cout << "\nTEST READ  FILE:\nFILENAME: balldata1.data" << endl;
    CollectionSB* collection7 = new CollectionSB();
    ifstream is;
    is.open("stress_ball1.data");
    cout << "\ncollection7 before reading: " << endl;
    cout << *collection7;
    if (is) {
        is >> *collection7;
    }
    cout << "\ncollection7 after reading: " << endl;
    cout << *collection7;
    is.close();
    is.clear();

    cout << "\nTEST READFILE:\nFILENAME: balldata2.data" << endl;
    is.open("stress_ball2.data");
    cout << "\ncollection7 before reading: " << endl;
    cout << *collection7;
    if (is) {
        is >> *collection7;
    }
    cout << "\ncollection7 after reading: " << endl;
    cout << *collection7;

        
    return true;
}

bool jntest() {

    // Test constructors
    cout << "TEST CONSTRUCTORS:" << endl;
    CollectionJN collection0;
    CollectionJN collection1(10);
    CollectionJN collection2(10);
    CollectionJN collection3(20);
    cout << "\nCollection 0: " << endl;
    collection0.print_items();
    cout << "\nCollection 1: " << endl;
    collection1.print_items();
    cout << "\nCollection 2: " << endl;
    collection2.print_items();

    // Test destructor
    cout << "\nTEST DESTRUCTOR:" << endl;
    CollectionJN* collection4 = new CollectionJN(10);
    CollectionJN* collection5 = new CollectionJN(15);
    delete collection4;
    collection5->make_empty();
    cout << collection5->is_empty() << endl;

    // Test Collection class methods
    cout << "\nTEST RESIZE: " << endl;
    cout << collection2.get_size() << "," << collection2.get_capacity() << endl;
    collection2.resize();
    cout << collection2.get_size() << "," << collection2.get_capacity() << endl;

    // Test inserting large number of items
    cout << "\nTEST INSERTING: " << endl;
    for (int i = 0; i < 20; ++i) {
        collection2.insert_item(Jeans());
        cout << "collection2 after "  << i << " insertion: " << collection2.get_size() << "," << collection2.get_capacity() << endl;
    }

    // Test sortings
    cout << "\ncollection2 before bubble sort: " << endl;
    collection2.print_items();
    sort_by_size(collection2, Sort_choice::bubble_sort);
    cout << "\ncollection2 after bubble sort: " << endl;
    collection2.print_items();
    cout << "\ncollection3 before selection sort: " << endl;
    collection3.print_items();
    sort_by_size(collection3, Sort_choice::selection_sort);
    cout << "\ncollection3 after selection sort: " << endl;
    collection3.print_items();
    cout << "\ncollection1 before insertion sort: " << endl;
    collection1.print_items();
    sort_by_size(collection1, Sort_choice::insertion_sort);
    cout << "\ncollection1 after insertion sort: " << endl;
    collection1.print_items();

    // Test additional functions:
    cout << "\nTEST MAKE A UNION: " << endl;
    cout << "Make a union of collection1 and collection3: " << endl;
    CollectionJN collection6 = make_union(collection1, collection3);
    collection6.print_items();

    cout << "\nTEST SWAP: " << endl;
    cout << "Swap collection1 and collection3: " << endl;
    cout << "collection1 and 3, respectively, before swapping: " << endl;
    collection1.print_items();
    cout << endl;
    collection3.print_items();
    cswap(collection1, collection3);
    cout << endl;
    cout << "collection1 and 3 respectively after swapping" << endl;
    collection1.print_items();
    cout << endl;
    collection3.print_items();


    // TEST READ FILE
    cout << "\nTEST READ  FILE:\nFILENAME: jeans1.data" << endl;
    CollectionJN* collection7 = new CollectionJN();
    ifstream is;
    is.open("jeans1.data");
    cout << "\ncollection7 before reading: " << endl;
    cout << *collection7;
    if (is) {
        is >> *collection7;
    }
    cout << "\ncollection7 after reading: " << endl;
    cout << *collection7;
    is.close();
    is.clear();

    cout << "\nTEST READFILE:\nFILENAME: jeans2.data" << endl;
    is.open("jeans2.data");
    cout << "\ncollection7 before reading: " << endl;
    cout << *collection7;
    if (is) {
        is >> *collection7;
    }
    cout << "\ncollection7 after reading: " << endl;
    cout << *collection7;

    return true;
}

int main() {
    int answer;
    cout << "What version to test: stress_ball (=0) or jeans (=1): ";
    cin >> answer;
    if (answer == 0)
        sbtest();
    else if (answer == 1)
        jntest();
    else
        cout << "Wrong value: " << answer << endl;
    return 0; 
}
