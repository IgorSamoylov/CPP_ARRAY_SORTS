#include "ARRAY_SORTS.h"

minstd_rand generator;
//knuth_b generator;

int shift = 0;
int random_generator(vector<int> seed) {
    
    generator.seed(seed[shift++ % seed.size()]);
    int r = generator();
    //cout << "r:" << r << endl;
    return r;
}