#include "ARRAY_SORTS.h"

// Quick sort algorithm for Stack allocation
vector<int> quick_sort(vector<int> v) {

    int size = v.size();
    if (size < 2) return v;

    int pivot_index = random_generator(v) % size;
    int pivot_value = v[pivot_index];

    vector<int> lower_values;
    vector<int> higher_values;
    for (int i = 0; i < size; ++i) {
        if (i == pivot_index) continue;
        if (v[i] < pivot_value) lower_values.push_back(v[i]);
        else higher_values.push_back(v[i]);
    }

    vector<int> sort_lower = quick_sort(lower_values);
    vector<int> sort_higher = quick_sort(higher_values);

    vector<int> result_vector;
    move(sort_lower.begin(), sort_lower.end(), back_inserter(result_vector));
    result_vector.push_back(pivot_value);
    move(sort_higher.begin(), sort_higher.end(), back_inserter(result_vector));

    return result_vector;
}
