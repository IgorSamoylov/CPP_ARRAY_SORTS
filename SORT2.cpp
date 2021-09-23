#include "ARRAY_SORTS.h"

// Quick sort algorithm for Heap allocation
vector<int>* quick_sort2(vector<int>* v) {

    int size = v->size();
    if (size < 2) return v; 

    int pivot_index = random_generator(*v) % size; //cout << endl << "pivot index: " << pivot_index << endl;
    int pivot_value = (*v)[pivot_index];

    vector<int>* lower_values = new vector<int>();
    vector<int>* higher_values = new vector<int>();
    //unique_ptr<vector<int>> lower_values(new vector<int>);

    for (int i = 0; i < size; ++i) {
        if (i == pivot_index) continue;
        if ((*v)[i] < pivot_value) (*lower_values).push_back((*v)[i]);
        else (*higher_values).push_back((*v)[i]);
    }

    vector<int>* sort_lower = quick_sort2(lower_values); 
    vector<int>* sort_higher = quick_sort2(higher_values); 

    vector<int>* result_vector = new vector<int>();
    move(sort_lower->begin(), sort_lower->end(), back_inserter(*result_vector));
    (*result_vector).push_back(pivot_value);
    move(sort_higher->begin(), sort_higher->end(), back_inserter(*result_vector));

    
    delete(sort_lower);
    delete(sort_higher);

    //delete(lower_values);
    //delete(higher_values);
    
    return result_vector;
}