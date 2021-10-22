/*
* QuickSort recursive algorithm for Heap allocation primitive T array
*/

#pragma once

#include "ARRAY_SORTS.h"

// Auxiliary sorts for extreme cases
template <class T>
void insertion_sort(T* v, size_t size) {

	for (size_t i = 1; i < size; ++i) {
		size_t t = i;
		while (t > 0 && v[t - 1] > v[t]) {
			T tmp = v[t];
			v[t] = v[t - 1];
			v[t - 1] = tmp;
			//swap(v[t], v[t - 1]);
			t--;
		}
	}
}

template <class T>
void bubble_sort(T* v, size_t size) {
	
	bool flag = true;
	while (flag) {
		flag = false;
		for (size_t i = 0; i < size - 1; ++i)
			if (v[i] > v[i + 1]) {
				//swap(v[i], v[i + 1]);
				T tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				flag = true;
			}
	}
}

template <class T>
void quick_sort_prim_t(T* v, size_t size) {
	/*
	if (size < 2) return;
	else if (size == 2) {
		if (v[0] > v[1]) {
			int tmp = v[0];
			v[0] = v[1];
			v[1] = tmp;
		}
		return;
	}*/
	if (size < 40) {
		insertion_sort(v, size);
		return;
	}
	/*else if (size < 55) {
		bubble_sort(v, size);
		return;
	}*/

	T pivot_value = *v;
	size_t pivot_values_counter = 0;

	T* lower_values = new T[size]; size_t lower_size = 0;
	T* higher_values = new T[size]; size_t higher_size = 0;

	for (size_t i = 0; i < size; ++i) {
		T val = *(v + i);
		if (val < pivot_value) lower_values[lower_size++] = val;
		else if (val == pivot_value) pivot_values_counter++;
		else higher_values[higher_size++] = val;
	}

	quick_sort_prim_t(lower_values, lower_size);
	quick_sort_prim_t(higher_values, higher_size);

	// Fill the pivot values after lower values into lower values array
	for (size_t i = lower_size; i < lower_size + pivot_values_counter; ++i)
		lower_values[i] = pivot_value;

	// Append higher values after lower and pivot values into lower values array
	constexpr size_t item_size = sizeof(*v);
	memcpy_s(lower_values + lower_size + pivot_values_counter, higher_size * item_size,
		higher_values, higher_size * item_size);

	delete[](higher_values);

	// Copy lower values array to the source array
	memcpy_s(v, size * item_size, lower_values, size * item_size);

	delete[](lower_values);
}



