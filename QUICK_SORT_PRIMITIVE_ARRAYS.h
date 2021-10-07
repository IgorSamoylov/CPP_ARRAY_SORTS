#pragma once

#include "ARRAY_SORTS.h"

template <class T>
void quick_sort_prime(T* v, size_t size) {

	T* buffer = new T[size];

	size_t pivot_index = 0;
	T pivot_value = v[pivot_index];
	size_t left_side = 0, right_side = size - 1, pivot_val_counter = 0;
	
	
	for (size_t i = 0; i < size; ++i) {
		T val = v[i];
		if (val < pivot_value) buffer[left_side++] = val;
		else if (val == pivot_value) ++pivot_val_counter;
		else buffer[right_side--] = val;
	}
}

