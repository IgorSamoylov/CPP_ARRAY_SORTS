#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <memory>
#include <thread>
#include <future>
using namespace std;

// Size of array containers for testing
const size_t VECTOR_SIZE = 300;
// Range of int values [0, VALUES_RANGE) for testing
const int VALUES_RANGE = 100;

extern knuth_b& random_generator;

void print_multithread(string n);

void print_vector(const vector<int>& v);

void print_vector_u(unique_ptr<vector<int>>&& v);

void print_array(const int* data, size_t size);

unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v);
