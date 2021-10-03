#include "ARRAY_SORTS.h"

// Quick sort algorithm for Stack allocation
void quick_sort(vector<int>&  v) {

    size_t size = v.size();
    if (size < 2) return;
    else if (size == 2) {
        if (v[0] > v[1]) swap(v[0], v[1]);
        return;
    }

    //int pivot_index = 0;//  random_generator(v) % size;
    int pivot_value = v[0];
    size_t pivot_values_counter = 0;

    vector<int> lower_values; lower_values.reserve(size);
    vector<int> higher_values;
    for (int val : v) {
        if (val < pivot_value) lower_values.push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values.push_back(val);
    }

    quick_sort(lower_values);
    quick_sort(higher_values);

    for (size_t i = 0; i < pivot_values_counter; ++i) lower_values.push_back(pivot_value);
    move(higher_values.begin(), higher_values.end(), back_inserter(lower_values));

    move(lower_values.begin(), lower_values.end(), v.begin());
}
