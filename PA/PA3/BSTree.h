#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  int search_time;

  // Node constructor
  Node(int val = 0, Node *l = nullptr, Node *r = nullptr)
      : value(val), left(l), right(r), search_time(0) {}

  // copy helper
  Node *copy()
  {
    Node *root = new Node(value);
    if (left != nullptr)
    {
      root->left = left->copy();
    }
    if (right != nullptr)
    {
      root->right = right->copy();
    }
    return root;
  }
};

struct BSTree
{
public:
  // constructors
  BSTree() : size(0), root(nullptr) {}
  // copy constructor
  BSTree(const BSTree &other);
  // move constructor
  BSTree(BSTree &&other);
  // copy assignment
  BSTree &operator=(const BSTree &other);
  // move assignment
  BSTree operator=(BSTree &&other);
  ~BSTree();

  const Node *get_root() const { return root; }
  const int get_size() const { return size; }
  int get_height() { return height(root); }
  Node *insert(int);
  Node *search(int);
  int get_total_search_time(Node *);
  void update_search_times();
  float get_average_search_time();
  ostream &inorder(ostream &);
  ostream &print_level_by_level(ostream &);\

private:
  int size;
  Node *root;

  // you may need helper functions to be called recursively
  // this is one example:
  void deleteTree(Node *);
  Node *insert(Node *, Node *);
  Node *search(int, Node *);
  void update_each_node(Node *, int);
  int height(Node *);
  void pretty_print_node(ostream &, Node *);
  void in_order_traversal(Node *, ostream &);
};

// print a BSTree
ostream &operator<<(ostream &, BSTree &);

// print a node
ostream &operator<<(ostream &, Node);

// read in a tree from a file
istream &operator>>(istream &, BSTree &);

#endif
