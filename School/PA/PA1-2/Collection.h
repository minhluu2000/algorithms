#ifndef COLLECTION_H
#define COLLECTION_H

#include "Stress_ball.h"

// PART 1
class Collection {
    Stress_ball* array;
    int size;
    int capacity;
    public:
        Collection();
        Collection(int);
        Collection(const Collection&);
        Collection& operator=(const Collection&); // Copy assignment operator
        ~Collection(); // Destructor
        Collection(Collection&&); // Move constructor
        Collection& operator=(Collection&&); // Move assignment operator
        void resize();
        void insert_item(const Stress_ball&);
        bool contains(const Stress_ball&) const;
        Stress_ball remove_any_item();
        void remove_this_item(const Stress_ball);
        void make_empty();
        Stress_ball* get_array_ref();
        int get_size();
        int get_capacity();
        bool is_empty() const;
        int total_items() const;
        int total_items(Stress_ball_sizes) const;
        int total_items(Stress_ball_colors) const;
        void print_items() const;
        Stress_ball& operator[](int);
        const Stress_ball& operator[](int) const;
};


// PART 2
Stress_ball_colors str_to_color(string);
Stress_ball_sizes str_to_size(string);
void bubble_sort(Collection&);
void insertion_sort(Collection&);
void selection_sort(Collection&);
istream& operator>>(istream&, Collection&);
ostream& operator<<(ostream&, const Collection&);
Collection make_union(const Collection&, const Collection&);
void cswap(Collection&, Collection&); // I renamed from swap to cswap to prevent confusion with the built-in swap function
enum class Sort_choice {bubble_sort, insertion_sort, selection_sort};
void sort_by_size(Collection&, Sort_choice);

#endif