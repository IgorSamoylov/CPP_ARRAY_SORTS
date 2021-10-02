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

int random_generator(vector<int> seed);
void print_multithread(string n);

const size_t VECTOR_SIZE = 4000;
const size_t THREAD_RECURSION_BORDER = 200;

vector<int> quick_sort(const vector<int>& v);
vector<int>* quick_sort2(vector<int>* v);
unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v);

template <typename T>
unique_ptr<vector<T>> quick_sort_multithreading_T(unique_ptr<vector<T>> v);



