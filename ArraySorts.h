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

size_t random_generator();
void print_multithread(string n);

const size_t VECTOR_SIZE = 2000;

unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v);






