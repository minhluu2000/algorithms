#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"
using namespace std;

void generate_random(int*& A, int size) {
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 10;
    }
}

void print(int*& A, int size) {
    for (int i = 0; i < size; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int*& A, int size) {
    int counter = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            ++counter;
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    cout << "Number of operations: " << counter << endl;
}


void insertion_sort(int*& A, int size) {
    for (int i = 1; i < size; ++i) {
        int num = A[i];
        int j = i - 1;
        
         (j >= 0 && A[j] > num) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = num;
    }
}

void selection_sort(int*& A, int size) {
    int smallest;
    for (int i = 0; i < size - 1; ++i) {
        smallest = i;
        for (int j = i + 1; j < size; ++j) {
            if(A[smallest] > A[j]) {
                smallest = j;
            }
        }
        if (smallest != i) {
            int temp = A[i];
            A[i] = A[smallest];
            A[smallest] = temp;
        }
    }
}

void counting_sort(int*& A, int size) {
    int counter = 0;
    int* cat = new int[10]; // An array to store the number of occcurrence for each number in the unsorted list
    ++counter;
    int* sorted = new int[size]; // This array is for holding sorted elements
    ++counter;
    for (int i = 0; i < size; ++i) { // Count occurence
        ++cat[A[i]];
        ++counter;
    }
    for (int i = 1; i < 10; ++i) { // Current element = current element + previous element
        cat[i] += cat[i - 1];
        ++counter;
    }
    for (int i = 0; i < size; ++i) { // Moving each element to the correct position
        sorted[cat[A[i]] - 1] = A[i];
        --cat[A[i]];
        ++counter;
    }
    cout << "Number of operations: " << counter << endl;
    delete[] A;
    A = sorted;
    delete[] cat;
}

void radix_sort() {

}


int main() {
    int size = 10000;
    int* A = new int[size];
    generate_random(A, size);
    // print(A, size);
    bubble_sort(A, size);
    // print(A, size);
    // insertion_sort(A, size);
    // selection_sort(A, size);
    counting_sort(A, size);
    // print(A, size);
    delete[] A;
    return 0;
}