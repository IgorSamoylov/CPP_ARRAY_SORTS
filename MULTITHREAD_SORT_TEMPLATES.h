#pragma once

#include "ARRAY_SORTS.h"


// Multithreading Quick sort algoritm for templates types


template <typename T>
unique_ptr<vector<T>> quick_sort_multithreading_T(unique_ptr<vector<T>> v) {

    size_t size = v->size();
    if (size < 2) return v;
    else if (size == 2) {
        if ((*v)[1] < (*v)[0]) swap(v->front(), v->back());
        return v;
    }

    int pivot_index = 0;// size >> 1;

    int pivot_value = (*v)[pivot_index];
    int pivot_values_counter = 0;

    unique_ptr <vector<T>> lower_values(new vector<T>);
    unique_ptr <vector<T>> higher_values(new vector<T>);

    for (size_t i = 0; i < size; ++i) {
        int val = (*v)[i];
        if (val < pivot_value) lower_values->push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values->push_back(val);
    }

    packaged_task <unique_ptr<vector<T>>(unique_ptr<vector<T>>)>
        lower_sort(quick_sort_multithreading_T);
    packaged_task <unique_ptr<vector<T>>(unique_ptr<vector<T>>)>
        higher_sort(quick_sort_multithreading_T);

    future<unique_ptr<vector<T>>> lower_future = lower_sort.get_future();
    future<unique_ptr<vector<T>>> higher_future = higher_sort.get_future();

    thread thread1(move(lower_sort), move(lower_values)); thread1.detach();
    thread thread2(move(higher_sort), move(higher_values)); thread2.detach();

    unique_ptr<vector<T>> result = lower_future.get();
    unique_ptr<vector<T>> higher_part = higher_future.get();

    fill_n(back_inserter(*result), pivot_values_counter, pivot_value);
    move(higher_part->begin(), higher_part->end(), back_inserter(*result));

    
    return result;
}


