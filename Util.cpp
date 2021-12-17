#include "ArraySorts.h"
#include <mutex>

// Simple and fast random generator for quick sort functions usage.
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
knuth_b generator(seed);
knuth_b& random_generator = generator;


mutex mutex1;
void print_multithread(string n) {
    mutex1.lock();
    cout << n << endl;
    mutex1.unlock();
}

void print_vector(const vector<int>& v) {
    for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
    cout << endl;
}

void print_vector_u(unique_ptr<vector<int>>&& v) {
    for_each(v->begin(), v->end(), [](int n) {cout << n << " "; });
    cout << endl;
}

void print_array(const int* data, size_t size) {
    for (size_t i = 0; i < size; i++) cout << data[i] << " ";
    cout << endl;
}