#include "ARRAY_SORTS.h"

int random_generator() {
    minstd_rand generator;
    generator.seed(time(nullptr));
    return generator();
}