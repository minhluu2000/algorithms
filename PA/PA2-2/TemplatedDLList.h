#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
  explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// doubly linked list node
template<typename T>
struct DLListNode {
  T obj;
  DLListNode *prev, *next;
  // constructor
  DLListNode(T e=T(), DLListNode *p = nullptr, DLListNode *n = nullptr)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list class
template<typename T>
class DLList {
  private:
    DLListNode<T> header, trailer;
  public:
    DLList() : header(T()), trailer(T()) // default constructor
    { header.next = &trailer; trailer.prev = &header; }
    DLList(const DLList& dll); // copy constructor
    DLList(DLList&& dll); // move constructor
    ~DLList(); // destructor
    DLList& operator=(const DLList& dll); // copy assignment operator
    DLList& operator=(DLList&& dll); // move assignment operator
    // return the pointer to the first node
    DLListNode<T>* first_node() const { return header.next; } 
    // return the pointer to the trailer
    const DLListNode<T>* after_last_node() const { return &trailer; }
    // return if the list is empty
    bool is_empty() const { return header.next == &trailer; }
    T first() const; // return the first object
    T last() const; // return the last object
    void insert_first(T obj); // insert to the first node
    T remove_first(); // remove the first node
    void insert_last(T obj); // insert to the last node
    T remove_last(); // remove the last node
    void insert_after(DLListNode<T> &p, T obj);
    void insert_before(DLListNode<T> &p, T obj);
    T remove_after(DLListNode<T> &p);
    T remove_before(DLListNode<T> &p);
};

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll);



// copy constructor
template<typename T>
DLList<T>::DLList(const DLList<T>& dll) : header(T()), trailer(T()) {
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  DLListNode<T>* current = dll.first_node();
  while (current != dll.after_last_node()) {
    this->insert_last(current->obj);
    current = current->next;
  }
}

// move constructor
template<typename T>
DLList<T>::DLList(DLList<T>&& dll) {
  header.next = dll.header.next;
  trailer.prev = dll.trailer.prev;
  dll.header.next->prev = &header;
  dll.trailer.prev->next = &trailer;
  dll.header.next = &dll.trailer;
  dll.trailer.prev = &dll.header;
}

// copy assignment operator
template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& dll) {
  if (this != &dll) {
    // Clean out the list
    DLListNode<T>* current = header.next;
    while (current != &trailer) {
      DLListNode<T>* next = current->next;
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
template<typename T>
DLList<T>& DLList<T>::operator=(DLList<T>&& dll) {
  if (this != &dll) {
    DLListNode<T>* current = header.next;
    while (current != &trailer) {
      DLListNode<T>* next = current->next;
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
template<typename T>
DLList<T>::~DLList() {
  DLListNode<T>* current = header.next;
  while (current != &trailer) {
    DLListNode<T>* next = current->next;
    delete current;
    current = next;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// insert a new object as the first one
template<typename T>
void DLList<T>::insert_first(T obj) { 
  DLListNode<T>* node = new DLListNode<T>(obj, &header, header.next);
  header.next->prev = node;
  header.next = node;
}

// insert a new object as the last one
template<typename T>
void DLList<T>::insert_last(T obj) {
  DLListNode<T>* node = new DLListNode<T>(obj, trailer.prev, &trailer);
  trailer.prev->next = node;
  trailer.prev = node;
}

// remove the first node from the list
template<typename T>
T DLList<T>::remove_first() { 
  if (is_empty()) {
    // throw an exception here
  }
  DLListNode<T>* node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}

// remove the last node from the list
template<typename T>
T DLList<T>::remove_last() {
  if (is_empty()) {
    throw EmptyDLList();
  }
  DLListNode<T>* node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}

// return the first object (do not remove)
template<typename T>
T DLList<T>::first() const { 
  if (is_empty()) {
    throw EmptyDLList();
  }
  return header.next->obj;
}

// return the last object (do not remove)
template<typename T>
T DLList<T>::last() const {
  if (is_empty()) {
    throw EmptyDLList();
  }
  return trailer.prev->obj;
}

// insert a new node after the node p
template<typename T>
void DLList<T>::insert_after(DLListNode<T> &p, T obj) {
  if (&p == trailer.prev) {
    insert_last(obj);
    return;
  }
  DLListNode<T>* current = header.next;
  while (current != &p) {
    current = current->next;
  }
  DLListNode<T>* node = new DLListNode<T>(obj, current, current->next);
  current->next->prev = node;
  current->next = node;
}

// insert a new node before the node p
template<typename T>
void DLList<T>::insert_before(DLListNode<T> &p, T obj) {
  if (&p == header.next) {
    insert_first(obj);
    return;
  }
  DLListNode<T>* current = header.next;
  while (current->next != &p) {
    current = current->next;
  }
  DLListNode<T>* node = new DLListNode<T>(obj, current, current->next);
  current->next->prev = node;
  current->next = node;
}

// remove the node after the node p
template<typename T>
T DLList<T>::remove_after(DLListNode<T> &p) {
  if (is_empty()) {
    throw EmptyDLList();
  } else if (&p == trailer.prev) { // cannot remove the trailer
    // throw another exception here?
  } else if (&p == trailer.prev->prev) {
    T obj = trailer.prev->prev->obj;
    remove_last();
    return obj;
  } else if (&p == &header) {
    T obj = header.next->obj;
    remove_first();
    return obj;
  }
  DLListNode<T>* current = header.next;
  while (current->prev != &p) { // Stop at the target node (the one after the parameter)
    current = current->next;
  }
  T obj = current->obj;
  current->next->prev = current->prev;
  current->prev->next = current->next;
  delete current;
  return obj;
  
}

// remove the node before the node p
template<typename T>
T DLList<T>::remove_before(DLListNode<T> &p) {
  if (is_empty()) {
    throw EmptyDLList();
  } else if (&p == header.next) { 
    throw EmptyDLList();
  } else if (&p == header.next->next) {
    T obj = header.next->next->obj;
    remove_first();
    return obj;
  } else if (&p == &trailer) {
    T obj = trailer.prev->obj;
    remove_last();
    return obj;
  }
  DLListNode<T>* current = header.next;
  while (current->next != &p) { // Stop at the target node (the one before the parameter)
    current = current->next;
  }
  T obj = current->obj;
  current->next->prev = current->prev;
  current->prev->next = current->next;
  delete current;
  return obj;
}

// output operator
template<typename T>
ostream& operator<<(ostream& out, const DLList<T>& dll) {
  if (dll.first_node() == dll.after_last_node()) {
    out << "Empty linked list";
    return out;
  }
  DLListNode<T>* current = dll.first_node();
  while (current != dll.after_last_node()->prev) {
    out << current->obj << "->";
    current = current->next;
  }
  out << current->obj << endl;
  return out;
}


#endif
