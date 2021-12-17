#include "ArraySorts.h"


unsigned seed = chrono::system_clock::now().time_since_epoch().count();
knuth_b generator(seed);


size_t random_generator() {
    return generator();
}

#include <mutex>
mutex mutex1;
void print_multithread(string n) {
    mutex1.lock();
    cout << n << endl;
    mutex1.unlock();
}

void print_vector(vector<int>& v) {
    for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
}