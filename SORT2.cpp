#include "ARRAY_SORTS.h"

// Quick sort algorithm for Heap allocation
vector<int>* quick_sort2(vector<int>* v) {

    size_t size = v->size();
    if (size < 2) return v; 
    else if (size == 2) {
        if ((*v)[0] > (*v)[1]) swap(v->front(), v->back());
        return v;
    }

    int pivot_index = size >> 1;
    int pivot_value = (*v)[pivot_index];
    size_t pivot_values_counter = 0;

    vector<int>* lower_values = new vector<int>();
    vector<int>* higher_values = new vector<int>();
    
    for (int val : *v) {
        if (val < pivot_value) lower_values->push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values->push_back(val);
    }

    vector<int>* sort_lower = quick_sort2(lower_values); 
    vector<int>* sort_higher = quick_sort2(higher_values); 

    vector<int>* result_vector = new vector<int>();
    move(sort_lower->begin(), sort_lower->end(), back_inserter(*result_vector));
    for (size_t i = 0; i < pivot_values_counter; ++i) result_vector->push_back(pivot_value);
    move(sort_higher->begin(), sort_higher->end(), back_inserter(*result_vector));

    delete(lower_values);
    delete(higher_values);
    
    return result_vector;
}