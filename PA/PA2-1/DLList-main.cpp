// test of the DLList class

#include <iostream>
#include <cstdlib>
#include "DLList.h"

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList dll;
  cout << "list: " << dll << endl << endl;
  
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_first(i);
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  // add tests for insert_after, insert_before
  cout << "Test insert_after and insert_before using list2:" << endl;
  DLListNode* current = dll2.first_node();
  cout << "Insert 1000 up front using insert_before." << endl;
  dll2.insert_before(*current, 1000);
  for (int i = 1; i < 8; ++i) {
    current = current->next;
  }
  cout << "Insert 420 and 69 in the middle of the list." << endl;
  dll2.insert_before(*current, 420);
  dll2.insert_after(*current, 69);
  cout << "Insert 99 at the end of the list using insert after." << endl;
  while (current != dll2.after_last_node()->prev) {
    current = current->next;
  }
  dll2.insert_after(*current, 99);
  cout << "list2 after insert " << dll2 << endl;


  // add tests for remove_after, remove_before
  cout << "Test remove_after and remove_before using list2:" << endl;
  current = dll2.first_node();
  try {
    cout << "Try to remove header." << endl;
    dll2.remove_before(*current);
  }
  catch(...) {
    cout << "Remove header caught!" << endl;
  }
  cout << "Remove 1000 using remove_before." << endl;
  current = current->next;
  dll2.remove_before(*current);
  for (int i = 1; i < 9; ++i) {
    current = current->next;
  }
  cout << "Remove 420 and 69 in the middle of the list." << endl;
  dll2.remove_before(*current);
  dll2.remove_after(*current);
  cout << "Remove 99 at the end of the list using remove after." << endl;
  while (current != dll2.after_last_node()->prev->prev) {
    current = current->next;
  }
  dll2.remove_after(*current);
  cout << "list2 after remove  " << dll2 << endl;

  // Test move constructor
  cout << "Test copy and move constructor" << endl;
  DLList dll4 = move(dll2); //move constructor
  cout << dll4 << endl;
  DLList dll6;
  dll6 = move(dll2); //move assignment
  dll6 = dll2; //copy assignment
  cout << "Everything works!" << endl;
  return 0;
}
