// Add code everywhere you see this:
// Your code >>>

#include <iostream>

using namespace std;

int num_resize; // the number of resizes
int num_copy;  // the number of copied elements

void resize_array(int*& array, int& capacity)
{
  // Your code >>> resize array by doubling its capacity
  // Your code >>> use tracker variables:
  //           >>> num_resize and num_copy

  num_resize++;
  int* new_array = new int[capacity * 2];
  for (int i = 0; i < capacity; ++i) {
    new_array[i] = array[i];
    num_copy++;
  }
  delete[] array;
  array = new_array;
  capacity *= 2;
}

void add_elements(int start, int total_elem)
{
    // Clear tracker variables
    num_resize = num_copy = 0;

    // Initialize array
    int capacity = start;
    int size = 0;
    int* A = new int[capacity];

    // Add elements to array
    while (size < total_elem)
    {
        cout << size << endl;
        if (size == capacity) // Array is full; add more space
        {
          resize_array(A, capacity); 
        }
        ++size;
        int index = size - 1;
        A[index] = index*index; // new values
    }

    // Print tracking info
    cout << "Total elements: " << total_elem << endl;
    cout << "Resize " << num_resize << " times." << endl;
    cout << "Copied " << num_copy << " elements in total." << endl;
}

int main()
{
  // test this program
  int total_elem[]= {1, 2, 4/*, 64, 1024*/};
  for (int i = 0; i < 3; i++)
    add_elements(1, total_elem[i]);
}