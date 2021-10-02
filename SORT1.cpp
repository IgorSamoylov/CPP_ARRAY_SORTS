#include "ARRAY_SORTS.h"

// Quick sort algorithm for Stack allocation
vector<int> quick_sort(vector<int> v) {

    size_t size = v.size();
    if (size < 2) return v;

    int pivot_index = 0;// random_generator(v) % size;
    int pivot_value = v[pivot_index];
    size_t pivot_values_counter = 0;

    vector<int> lower_values;
    vector<int> higher_values;
    for (int val : v) {
        if (val < pivot_value) lower_values.push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values.push_back(val);
    }

    vector<int> sort_lower = quick_sort(lower_values);
    vector<int> sort_higher = quick_sort(higher_values);

    vector<int> result_vector;
    move(sort_lower.begin(), sort_lower.end(), back_inserter(result_vector));
    for (size_t i = 0; i < pivot_values_counter; ++i) result_vector.push_back(pivot_value);
    move(sort_higher.begin(), sort_higher.end(), back_inserter(result_vector));

    return result_vector;
}
