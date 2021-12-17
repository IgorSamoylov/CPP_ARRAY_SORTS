/* 
* Simple implementations of MergeSort algorithm based on inner CPP merge functions
*/ 

#pragma once

#include "ArraySorts.h"

template<class Iter>
void merge_sort_inplace(Iter first, Iter last)
{
    if (1 < last - first) {
        Iter middle = first + (last - first) / 2;
        merge_sort_inplace(first, middle);
        merge_sort_inplace(middle, last);
        std::inplace_merge(first, middle, last);
    }
}


template <typename T>
void merge_sort(std::vector<T>& array) {
    if (1 < array.size()) {
        std::vector<T> array1(array.begin(), array.begin() + array.size() / 2);
        merge_sort(array1);
        std::vector<T> array2(array.begin() + array.size() / 2, array.end());
        merge_sort(array2);
        
        merge(array1.begin(), array1.end(),
            array2.begin(), array2.end(), array.begin());
    }
}




