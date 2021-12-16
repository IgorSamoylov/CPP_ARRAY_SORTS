/*
* Most fast version of the iterative MergeSort algorithm, which used
* M(n) of memory in a fixed auxiliary buffer
*/

#pragma once

template <typename T>
void merge_sort_iterative_prim_t(T* v, size_t size) {
    T* buffer = new T[size];
    // step_increment means half of each processing group in each traversal
    for (size_t step_increment = 1; step_increment < size; step_increment *= 2) {

        // Pass through the source array with x2 increment of processing group
        size_t buffer_iter = 0;
        for (size_t i = 0; i < size; i += step_increment << 1) {

            size_t begin_index = i;
            size_t middle_index = i + step_increment;
            size_t end_index = middle_index + step_increment;

            //Perform Merging in processing group
            while (begin_index < i + step_increment
                && middle_index < end_index
                && middle_index < size) {

                if (v[begin_index] <= v[middle_index])
                    buffer[buffer_iter++] = v[begin_index++];
                else buffer[buffer_iter++] = v[middle_index++];
            }
            // Appending tails in each processing group
            while (begin_index < i + step_increment
                && begin_index < size)
                buffer[buffer_iter++] = v[begin_index++];
            while (middle_index < end_index
                && middle_index < size)
                buffer[buffer_iter++] = v[middle_index++];
        }
        // Drop buffer entry to the source array in each traversal
        memcpy(v, buffer, size * sizeof(*v));
    }
    delete[] buffer;
}
