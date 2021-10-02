#include "ARRAY_SORTS.h"

// Multithreading Quick sort algoritm for int vector
unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v) {

    size_t size = v->size();

    // TODO: make sort function recursive call from thread if size < 100
    //vector<int>* v1;
    //if (size < 100) v1 = quick_sort2(&*v);
    //else v1 = &*v;

    //unique_ptr<vector<int>> v1 = move(v);


    if (size < 2) return v;
    else if (size == 2) {
        if ((*v)[1] < (*v)[0]) swap(v->front(), v->back());
        return v;
    }

    int pivot_index = 0;// size >> 1;
        
    int pivot_value = (*v)[pivot_index];
    int pivot_values_counter = 0;

    unique_ptr <vector<int>> lower_values = make_unique<vector<int>>();
    lower_values->reserve(size); // Reserve memory for merge this vector as the result vector in future

    unique_ptr <vector<int>> higher_values = make_unique<vector<int>>();
    
    for (size_t i = 0; i < size; ++i) {
        int val = (*v)[i];
        if (val < pivot_value) lower_values->push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values->push_back(val);
    }

    packaged_task <unique_ptr<vector<int>>(unique_ptr<vector<int>>)>
        lower_sort(quick_sort_multithreading);
    packaged_task <unique_ptr<vector<int>>(unique_ptr<vector<int>>)>
        higher_sort(quick_sort_multithreading);

    future<unique_ptr<vector<int>>> lower_future = lower_sort.get_future();
    future<unique_ptr<vector<int>>> higher_future = higher_sort.get_future();
    
    thread thread1(move(lower_sort), move(lower_values)); thread1.detach();
    thread thread2(move(higher_sort), move(higher_values)); thread2.detach();

    unique_ptr<vector<int>> result = move(lower_future.get()); // Taking sorted array of lower values as the result
    unique_ptr<vector<int>> higher_part = move(higher_future.get());

    fill_n(back_inserter(*result), pivot_values_counter, pivot_value); // fills middle values in the result
    move(higher_part->begin(), higher_part->end(), back_inserter(*result)); // append sorted vector of higher values

    return result;
}

