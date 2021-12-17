#include <vector>
#include <algorithm>
#include <iterator>
#include "ArraySorts.h"
using namespace std;

// Quick sort algorithm for vector of ints and Stack allocation
template <class T>
void quick_sort(vector<T>&  v) {

    size_t size = v.size();
    if (size < 2) return;
    else if (size == 2) {
        if (v[0] > v[1]) swap(v[0], v[1]);
        return;
    }

    size_t pivot_index = random_generator() % size;
    T pivot_value = v[pivot_index];
    size_t pivot_values_counter = 0;

    vector<T> lower_values; lower_values.reserve(size);
    vector<T> higher_values;
    for (T val : v) {
        if (val < pivot_value) lower_values.push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values.push_back(val);
    }

    quick_sort(lower_values);
    quick_sort(higher_values);

    fill_n(back_inserter(lower_values), pivot_values_counter, pivot_value);
    move(higher_values.begin(), higher_values.end(), back_inserter(lower_values));

    move(lower_values.begin(), lower_values.end(), v.begin());
}
