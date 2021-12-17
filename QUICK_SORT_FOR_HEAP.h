/*
* QuickSort algorithm for Heap allocated int vector
*/

#include <vector>
#include <algorithm>
#include <iterator>
#include "ARRAY_SORTS.h"
using namespace std;

template <class T>
void quick_sort_heap(vector<T>* v) {

    size_t size = v->size();
    if (size < 2) return; 
    else if (size == 2) {
        if ((*v)[0] > (*v)[1]) swap((*v)[0], (*v)[1]);
        return;
    }

    size_t pivot_index = random_generator() % size;
    T pivot_value = (*v)[pivot_index];
    size_t pivot_values_counter = 0;

    vector<int>* lower_values = new vector<int>(); 
    // Reserve memory for this vector, that will be a result vector
    lower_values->reserve(size); 
    vector<int>* higher_values = new vector<int>();
    
    for (T val : *v) {
        if (val < pivot_value) lower_values->push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values->push_back(val);
    }
    
    quick_sort_heap(lower_values); 
    quick_sort_heap(higher_values); 

    // fill the result vector with middle, pivot-equal values
    fill_n(back_inserter(*lower_values), pivot_values_counter, pivot_value);
    // appending higher values
    move(higher_values->begin(), higher_values->end(), back_inserter(*lower_values)); 

    delete(higher_values);
    move(lower_values->begin(), lower_values->end(), v->begin());
    delete(lower_values);
}