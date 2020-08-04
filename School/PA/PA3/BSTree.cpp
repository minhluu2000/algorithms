#include "BSTree.h"

// input / output operators
ostream &operator<<(ostream &out, BSTree &tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream &operator<<(ostream &out, Node &node)
{
  return out << "( " << node.value << ", "
             << node.search_time << " )";
}

istream &operator>>(istream &in, BSTree &tree)
{
  int next;
  if (in.fail())
  {
    cout << "Error, cannot open file!" << endl;
    cin.ignore();
    return in;
  }
  while (!in.eof())
  {
    in >> next; 
    tree.insert(next);
  }    
  return in;
}

///////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree &other)
{
  size = other.size;
  root = other.root->copy();
  update_search_times();
}

// copy assignment
BSTree &BSTree::operator=(const BSTree &other)
{
  if (this != &other)
  {
    deleteTree(root);
    size = other.size;
    root = other.root->copy();
    update_search_times();
  }
  return *this;
}

// move constructor
BSTree::BSTree(BSTree &&other)
{
  root = other.root;
  size = other.size;
  other.root = nullptr;
  other.size = 0;
}

// move assignment
BSTree BSTree::operator=(BSTree &&other)
{
  if (this != &other)
  {
    deleteTree(root);
    root = other.root;
    size = other.size;
    other.root = nullptr;
    other.size = 0;
  }
  return *this;
}

// destructor
BSTree::~BSTree()
{
  deleteTree(root);
  root = nullptr;
}

// insert
Node *BSTree::insert(int obj)
{
  Node *node = new Node(obj);
  root = insert(node, root);
  return node;
}

Node *BSTree::insert(Node *obj, Node *t)
{
  if (t == nullptr)
  {
    t = obj;
    ++size;
  }
  else if (obj->value < t->value)
    t->left = insert(obj, t->left);
  else if (obj->value > t->value)
    t->right = insert(obj, t->right);
  // else
  //   cout << "Item already inserted..." << endl;
  return t;
}

// search
Node *BSTree::search(int obj)
{
  return search(obj, root);
}

Node *BSTree::search(int obj, Node *t)
{
  while (t != nullptr)
  {
    if (obj < t->value)
      t = t->left;
    else if (obj > t->value)
      t = t->right;
    else
      return t;
  }
  cout << "Cannot find an object for " << obj << endl;
  return nullptr;
}

// height
int BSTree::height(Node *t)
{
  if (t == nullptr)
  {
    return -1;
  }
  int hlf = height(t->left);
  int hrt = height(t->right);
  return (hlf > hrt) ? 1 + hlf : 1 + hrt;
}

// update search
void BSTree::update_search_times()
{
  update_each_node(root, 1);
}

void BSTree::update_each_node(Node *t, int level)
{
  if (t == nullptr)
    return;
  t->search_time = level;
  update_each_node(t->left, level + 1);
  update_each_node(t->right, level + 1);
}

// print in sorted fashion
ostream &BSTree::inorder(ostream &out)
{
  in_order_traversal(root, out);
  return out;
}


// helper for print in sorted fashion
void BSTree::in_order_traversal(Node *t, ostream &out)
{
  if (t == nullptr)
  {
    return;
  }
  in_order_traversal(t->left, out);
  out << t->value << "[" << t->search_time << "]" << endl;
  in_order_traversal(t->right, out);
}

// delete tree
void BSTree::deleteTree(Node *t)
{
  // PostOrder tranversal
  if (t == nullptr)
    return;
  if (t->left != nullptr)
    deleteTree(t->left);
  if (t->right != nullptr)
    deleteTree(t->right);
  delete t;
}

// implemented
void BSTree::pretty_print_node(ostream &out, Node *node)
{
  out << node->value << "[" << node->search_time << "] ";
}

// implemented
ostream &BSTree::print_level_by_level(ostream &out)
{
  /*
    print the tree using a BFS 
    output should look like this if we dont have a full tree

    4
    2 6
    1 X 5 7
    X X X X X X X 9

    it will be helpfull to do this part iterativly, 
    so do the BFS with the std stack data structure.

    it may also be helpfull to put the entire tree into a vector 
    (probably google this if you dont know how to do it)
  */

  if (root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node *> current_level;
  vector<Node *> next_level;
  current_level.push_back(root);
  while (hasNodes)
  {
    hasNodes = false;
    for (auto node : current_level)
    {
      if (node != nullptr)
      {
        pretty_print_node(out, node);
        if (node->left != nullptr)
          hasNodes = true;
        if (node->right != nullptr)
          hasNodes = true;

        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
      else
      {
        out << "X ";
        next_level.push_back(nullptr);
        next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }
  return out;
}

// implemented
int BSTree::get_total_search_time(Node *node)
{
  if (node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
         get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if (total_search_time == 0)
    return -1;

  return ((float)total_search_time) / size;
}
