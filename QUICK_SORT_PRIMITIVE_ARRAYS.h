#pragma once

#include "ARRAY_SORTS.h"
#include <stack>

// Iterative implementation for QuickSort algorithm with M(1) memory usage

struct bound_ptrs {
	size_t left, right;
	bound_ptrs(size_t left, size_t right) : left(left), right(right) {}
};


template <class T>
void quick_sort_prime(T* v, size_t size) {

	T* buffer = new T[size];

	size_t pivot_index = 0;
	T pivot_value = v[pivot_index];
	size_t left_side = 0, right_side = size - 1, pivot_val_counter = 0;
	stack<bound_ptrs> ptr_stack;
	ptr_stack.push(bound_ptrs(left_side, right_side));
	
	while (ptr_stack.size() > 0) {
		bound_ptrs current_ptrs = ptr_stack.top(); ptr_stack.pop();
		size_t left = current_ptrs.left;
		size_t right = current_ptrs.right;
		for (size_t i = 0; i < size; ++i) {
			T val = v[i];
			if (val < pivot_value) buffer[left++] = val;
			else if (val == pivot_value) ++pivot_val_counter;
			else buffer[right--] = val;
		}
		if(left -current_ptrs.left > 0)
			ptr_stack.push(bound_ptrs(current_ptrs.left, left));
		if (current_ptrs.right - right > 0)
			ptr_stack.push(bound_ptrs(current_ptrs.right, right));
	}
}

