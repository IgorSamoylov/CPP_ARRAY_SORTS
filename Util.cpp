#include "ARRAY_SORTS.h"

//minstd_rand generator;
knuth_b generator;

int shift = 0;
int random_generator(vector<int> seed) {
    
    generator.seed(seed[shift++ % seed.size()]);
    int r = generator();
    //cout << "r:" << r << endl;
    return r;
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