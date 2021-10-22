/*
* Quick sort recursive algorithm for Heap allocation primitive int array
*/
#include <memory>

void quick_sort_prim(int* v, size_t size) {

    if (size < 2) return;
    else if (size == 2) {
        if (v[0] > v[1]) {
            int tmp = v[0];
            v[0] = v[1];
            v[1] = tmp;
        }  
        return;
    }

    int pivot_value = *v;
    size_t pivot_values_counter = 0;

    int* lower_values = new int[size]; size_t lower_size = 0;
    int* higher_values = new int[size]; size_t higher_size = 0;

    for (size_t i = 0; i < size; ++i) {
        int val = *(v + i);
        if (val < pivot_value) lower_values[lower_size++] = val;
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values[higher_size++] = val;
    }
    
    quick_sort_prim(lower_values, lower_size);
    quick_sort_prim(higher_values, higher_size);

    // Fill the pivot values after lower values into lower values array
    for (size_t i = lower_size; i < lower_size + pivot_values_counter; ++i)
        lower_values[i] = pivot_value;
    
    // Append higher values after lower and pivot values into lower values array
    constexpr size_t item_size = sizeof(*v);
    memcpy_s(lower_values + lower_size + pivot_values_counter, higher_size * item_size,
        higher_values, higher_size * item_size);
    delete[](higher_values);

    // Copy lower values array to the source array
    memcpy_s(v, size * item_size, lower_values, size * item_size);
    delete[](lower_values);
}