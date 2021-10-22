/*
* Multithreading Quick sort algoritm for vector of int's
*/

#include <vector>
#include <algorithm>
#include <iterator>
#include <thread>
#include <future>
using namespace std;

const size_t THREAD_RECURSION_BORDER = 200;

unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v) {

    size_t size = v->size();
    
    if (size < 2) return v;
    else if (size == 2) {
        if ((*v)[1] < (*v)[0]) swap(v->front(), v->back());
        return v;
    }

    int pivot_index = 0;// size >> 1; // This may be a random index
        
    int pivot_value = (*v)[pivot_index];
    int pivot_values_counter = 0;

    unique_ptr <vector<int>> lower_values = make_unique<vector<int>>();
    lower_values->reserve(size); // Reserves memory for merge this vector as the result vector in future

    unique_ptr <vector<int>> higher_values = make_unique<vector<int>>();
    
    for (size_t i = 0; i < size; ++i) {
        int val = (*v)[i];
        if (val < pivot_value) lower_values->push_back(val);
        else if (val == pivot_value) pivot_values_counter++;
        else higher_values->push_back(val);
    }

    unique_ptr<vector<int>> result = nullptr;
    unique_ptr<vector<int>> higher_part = nullptr;

    // If vector size stil big, we create and use threads, else - simple recursion calls 
    if (size > THREAD_RECURSION_BORDER) {
       
        packaged_task <unique_ptr<vector<int>>(unique_ptr<vector<int>>)>
            lower_sort(quick_sort_multithreading);
        packaged_task <unique_ptr<vector<int>>(unique_ptr<vector<int>>)>
            higher_sort(quick_sort_multithreading);

        future<unique_ptr<vector<int>>> lower_future = lower_sort.get_future();
        future<unique_ptr<vector<int>>> higher_future = higher_sort.get_future();

        thread thread1(move(lower_sort), move(lower_values)); thread1.detach();
        thread thread2(move(higher_sort), move(higher_values)); thread2.detach();

        result = move(lower_future.get()); // Taking sorted array of lower values as the result
        higher_part = move(higher_future.get());

    }
    else {
        result = move(quick_sort_multithreading(move(lower_values)));
        higher_part = move(quick_sort_multithreading(move(higher_values)));
    }

    fill_n(back_inserter(*result), pivot_values_counter, pivot_value); // fills middle values in the result vector
    move(higher_part->begin(), higher_part->end(), back_inserter(*result)); // append sorted vector of higher values

    return result;
}

