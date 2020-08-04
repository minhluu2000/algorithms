/*
Example code for local unit-testing of HW 4
*/

#include <iostream>
#include <string>
#include "Collection.h"
#include "Collection_test.h"

using std::cout;
using std::endl;

bool test() {

        // Test constructors
        cout << "TEST CONSTRUCTORS:" << endl;
        Collection collection0;
        Collection collection1(10);
        Collection collection2(10);
        Collection collection3(20);
        cout << "\nCollection 0: " << endl;
        collection0.print_items();
        cout << "\nCollection 1: " << endl;
        collection1.print_items();
        cout << "\nCollection 2: " << endl;
        collection2.print_items();

        // Test destructor
        cout << "\nTEST DESTRUCTOR:" << endl;
        Collection* collection4 = new Collection(10);
        Collection* collection5 = new Collection(15);
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
        cout << "\ncollection1 after insertion  sort: " << endl;
        collection1.print_items();

        // Test additional functions:
        cout << "\nTEST MAKE A UNION: " << endl;
        cout << "Make a union of collection1 and collection3: " << endl;
        Collection collection6 = make_union(collection1, collection3);
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

        cout << "\nTEST READFILE:\nFILENAME: balldata1.data" << endl;
        Collection* collection7 = new Collection();
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

        

        


        // try{
        //     cout << collection2[12] << endl;
        // }
        // catch(...){
        //     cout << "Caught" <<endl;
        // }
        // cout << collection2.remove_any_item() << endl;
        // cout << collection2.remove_any_item() << endl;
        // cout << collection2.remove_any_item() << endl;
        // try{
        //     cout << collection2.remove_any_item() << endl;
        // } catch(...) {
        //     cout << "Caught!" << endl;
        // }
        // collection2.print_items();
        // cout << collection2.get_size() << "," << collection2.get_capacity() << endl;
        // cout << collection2.get_size() << endl;
        // sort_by_size(collection2, Sort_choice::bubble_sort);

        
    return true;
}

int main() {
    test();
    return 0;
}
