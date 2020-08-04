// implementation of the DLList class

#include <stdexcept>
#include "DLList.h"


// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList& dll) : header(0), trailer(0) {
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  DLListNode* current = dll.first_node();
  while (current != dll.after_last_node()) {
    this->insert_last(current->obj);
    current = current->next;
  }
}

// move constructor
DLList::DLList(DLList&& dll) {
  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;
  dll.header.next->prev = &header;
  dll.trailer.prev->next = &trailer;
  dll.header.next = &dll.trailer;
  dll.trailer.prev = &dll.header;
}

// copy assignment operator
DLList& DLList::operator=(const DLList& dll) {
  if (this != &dll) {
    // Clean out the list
    DLListNode* current = header.next;
    while (current != &trailer) {
      DLListNode* next = current->next;
      delete current;
      current = next;
    }
    header.next = &trailer;
    trailer.prev = &header;

    // copy data
    current = dll.first_node();
    while (current != dll.after_last_node()) {
      this->insert_last(current->obj);
      current = current->next;
    }
  }
  return *this;
}

// move assignment operator
DLList& DLList::operator=(DLList&& dll) {
  if (this != &dll) {
    DLListNode* current = header.next;
    while (current != &trailer) {
      DLListNode* next = current->next;
      delete current;
      current = next;
    }

    // move new data
    header.next = dll.header.next;
    trailer.prev = dll.trailer.prev;
    dll.header.next->prev = &header;
    dll.trailer.prev->next = &trailer;
    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  }
  return *this;
}

// destructor
DLList::~DLList() {
  DLListNode* current = header.next;
  while (current != &trailer) {
    DLListNode* next = current->next;
    delete current;
    current = next;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
void DLList::insert_first(int obj) { 
  DLListNode* node = new DLListNode(obj, &header, header.next);
  header.next->prev = node;
  header.next = node;
}

// insert a new object as the last one
void DLList::insert_last(int obj) {
  DLListNode* node = new DLListNode(obj, trailer.prev, &trailer);
  trailer.prev->next = node;
  trailer.prev = node;
}

// remove the first node from the list
int DLList::remove_first() { 
  if (is_empty()) {
    // throw an exception here
  }
  DLListNode* node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}

// remove the last node from the list
int DLList::remove_last() {
  if (is_empty()) {
    // throw an exception here
  }
  DLListNode* node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}

// return the first object (do not remove)
int DLList::first() const { 
  if (is_empty()) {
    // throw an exception here
  }
  return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const {
  if (is_empty()) {
    // throw an exception here
  }
  return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj) {
  if (&p == trailer.prev) {
    insert_last(obj);
    return;
  }
  DLListNode* current = header.next;
  while (current != &p) {
    current = current->next;
  }
  DLListNode* node = new DLListNode(obj, current, current->next);
  current->next->prev = node;
  current->next = node;
}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj) {
  if (&p == header.next) {
    insert_first(obj);
    return;
  }
  DLListNode* current = header.next;
  while (current->next != &p) {
    current = current->next;
  }
  DLListNode* node = new DLListNode(obj, current, current->next);
  current->next->prev = node;
  current->next = node;
}

// remove the node after the node p
int DLList::remove_after(DLListNode &p) {
  if (is_empty()) {
    throw EmptyDLList();
  } else if (&p == trailer.prev) { // cannot remove the trailer
    // throw another exception here?
  } else if (&p == trailer.prev->prev) {
    int obj = trailer.prev->prev->obj;
    remove_last();
    return obj;
  } else if (&p == &header) {
    int obj = header.next->obj;
    remove_first();
    return obj;
  }
  DLListNode* current = header.next;
  while (current->prev != &p) { // Stop at the target node (the one after the parameter)
    current = current->next;
  }
  int obj = current->obj;
  current->next->prev = current->prev;
  current->prev->next = current->next;
  delete current;
  return obj;
  
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p) {
  if (is_empty()) {
    throw EmptyDLList();
  } else if (&p == header.next) { 
    throw EmptyDLList();
  } else if (&p == header.next->next) {
    int obj = header.next->next->obj;
    remove_first();
    return obj;
  } else if (&p == &trailer) {
    int obj = trailer.prev->obj;
    remove_last();
    return obj;
  }
  DLListNode* current = header.next;
  while (current->next != &p) { // Stop at the target node (the one before the parameter)
    current = current->next;
  }
  int obj = current->obj;
  current->next->prev = current->prev;
  current->prev->next = current->next;
  delete current;
  return obj;
}

// output operator
ostream& operator<<(ostream& out, const DLList& dll) {
  if (dll.first_node() == dll.after_last_node()) {
    out << "Empty linked list";
    return out;
  }
  DLListNode* current = dll.first_node();
  while (current != dll.after_last_node()->prev) {
    out << current->obj << "->";
    current = current->next;
  }
  out << current->obj << endl;
  return out;
}
