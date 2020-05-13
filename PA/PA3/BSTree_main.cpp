
#include <iostream>
#include <fstream>
#include "BSTree.h"

BSTree read_file(string file_name)
{
     /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
     BSTree new_tree;
     ifstream infile(file_name);
     infile >> new_tree;
     new_tree.update_search_times();
     return new_tree;
}

void write_file(BSTree &tree, string file_name)
{
     ofstream outfile("data-output-files/" + file_name);
     tree.inorder(outfile);
     outfile.close();
}

int main()
{
     // basic tests
     cout << "basic tests: " << endl;
     cout << "- call constructor " << endl;
     BSTree original; // constructor
     cout << "- insert elements " << endl;
     for (int i = 5; i <= 10; ++i)
     {
          original.insert(i);
     } // insert right
     for (int i = 1; i <= 4; ++i)
     {
          original.insert(i);
     } // insert left
     cout << "- update search time " << endl;
     original.update_search_times();
     cout << original;                                  // print
     cout << "- size: " << original.get_size() << endl; // get_size()
     cout << "- height: " << original.get_height() << endl
          << endl; // get_height()

     // test the copy constructor
     cout << "copy constructor tests: " << endl;
     cout << "- call copy constructor " << endl;
     BSTree copy_original(original);
     cout << copy_original;
     cout << "- size: " << copy_original.get_size() << endl; // get_size()
     cout << "- height: " << copy_original.get_height() << endl
          << endl; // get_height()

     // test the copy assignment
     cout << "copy assignment tests: " << endl;
     cout << "- call copy assignment operator " << endl;
     BSTree copy2_original = BSTree(original);
     cout << copy2_original;
     cout << "- size: " << copy2_original.get_size() << endl; // get_size()
     cout << "- height: " << copy2_original.get_height() << endl
          << endl; // get_height()

     // test move constructor and assignment operator
     cout << "move constructor tests: " << endl;
     cout << "- call move constructor " << endl;
     BSTree move_original(move(copy_original));
     cout << move_original;
     cout << "- size: " << move_original.get_size() << endl; // get_size()
     cout << "- height: " << move_original.get_height() << endl
          << endl; // get_height()

     cout << "move copy assignment tests: " << endl;
     cout << "- call move assignment operator " << endl;
     BSTree move2_original = move(copy2_original);
     cout << move2_original;
     cout << "- size: " << move2_original.get_size() << endl; // get_size()
     cout << "- height: " << move2_original.get_height() << endl
          << endl; // get_height()

     // test search
     cout << "test search: search for value 1 from the original bstree" << endl;
     cout << "found: " << original.search(1)->value << endl
          << endl;

     // test print in order
     cout << "print original in order: ";
     original.inorder(cout) << endl
                            << endl;

     // test destructor
     BSTree *destructor_test = new BSTree(original);
     delete destructor_test;

     // test search time
     for (int i = 1; i <= 12; i++)
     {
          string dir = "data-files/" + std::to_string(i);
          BSTree l = read_file(dir + "l");
          cout << "size: " << l.get_size() << endl;
          cout << "average search time linear " << i << " "
               << l.get_average_search_time() << endl;
          write_file(l, std::to_string(i) + "l" + ".txt");
          BSTree p = read_file(dir + "p");
          cout << "size: " << l.get_size() << endl;
          cout << "average search time perfect " << i << " "
               << p.get_average_search_time() << endl;
          write_file(p, std::to_string(i) + "p" + ".txt");
          BSTree r = read_file(dir + "r");
          cout << "size: " << l.get_size() << endl;
          cout << "average search time random " << i << " "
               << r.get_average_search_time() << endl;
          write_file(r, std::to_string(i) + "r" + ".txt");

          if (i <= 4)
          {
               cout << "prefect tree " << i << endl
                    << p;
          }

          cout << endl;
     }
}
