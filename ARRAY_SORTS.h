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


vector<int> quick_sort(vector<int> v);
vector<int>* quick_sort2(vector<int>* v);
unique_ptr<vector<int>> quick_sort_multithreading(unique_ptr<vector<int>> v);

int random_generator(vector<int> seed);
void print_multithread(string n);


