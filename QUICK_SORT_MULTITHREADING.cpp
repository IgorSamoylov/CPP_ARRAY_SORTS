#include "ARRAY_SORTS.h"

// Multithreading Quick sort algoritm
unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v) {

    int size = v->size();
    if (size < 2) return v;

    int pivot_index = random_generator(*v) % size; //cout << endl << "pivot index: " << pivot_index << endl;
    int pivot_value = (*v)[pivot_index];

    unique_ptr <vector<int>> lower_values (new vector<int>());
    unique_ptr <vector<int>> higher_values(new vector<int>());
    
    for (int i = 0; i < size; ++i) {
        if (i == pivot_index) continue;
        if ((*v)[i] < pivot_value) (*lower_values).push_back((*v)[i]);
        else (*higher_values).push_back((*v)[i]);
    }

    packaged_task <unique_ptr<vector<int>>(unique_ptr<vector<int>>)>
        lower_sort(quick_sort_multithreading);
    packaged_task <unique_ptr<vector<int>>(unique_ptr<vector<int>>)>
        higher_sort(quick_sort_multithreading);

    future<unique_ptr<vector<int>>> lower_future = lower_sort.get_future();
    future<unique_ptr<vector<int>>> higher_future = higher_sort.get_future();
    
    thread thread1(move(lower_sort), move(lower_values)); thread1.detach();
    thread thread2(move(higher_sort), move(higher_values)); thread2.detach();

    unique_ptr <vector<int>> sort_lower = lower_future.get();
    unique_ptr <vector<int>> sort_higher = higher_future.get();
    
    unique_ptr<vector<int>> result_vector(new vector<int>);
    move(sort_lower->begin(), sort_lower->end(), back_inserter(*result_vector));
    (*result_vector).push_back(pivot_value);
    move(sort_higher->begin(), sort_higher->end(), back_inserter(*result_vector));

    return result_vector;
}