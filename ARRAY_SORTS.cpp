#include "ARRAY_SORTS.h"

int VECTOR_SIZE = 150;








int main()
{
    vector<int> data(VECTOR_SIZE);

    minstd_rand generator; 
    generator.seed(time(nullptr));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        int value = generator() % 100;
        data[i] = value;
    }

    for_each(data.begin(), data.end(), [](int n) {cout << n << " "; });

    //vector<int> result_vector = quick_sort(data);
    //cout << endl << "Result:" << endl;
    //for_each(result_vector.begin(), result_vector.end(), [](int n) {cout << n << " "; });

    vector<int>* data_ptr = &data;
    vector<int>* result_vector = quick_sort2(data_ptr);
    cout << endl << "Result:" << endl;
    for_each((*result_vector).begin(), (*result_vector).end(),
        [](int n) {cout << n << " "; });

   
}




