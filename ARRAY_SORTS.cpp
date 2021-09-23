#include "ARRAY_SORTS.h"

class Tester {
 public:
    Tester() : data(nullptr),  result(nullptr) {}

    vector<int>* data;
    vector<int>* result;

    void prepare_test_vector(int vector_size) {
        data = new vector<int>(vector_size);
        
        minstd_rand generator;
        generator.seed(time(nullptr));

        for (int i = 0; i < vector_size; i++) {
            int value = generator() % 100;
            (*data)[i] = value;
        }
        cout << "Source:" << endl; 
        
    }

    void print_vector(vector<int> v) {
        for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
    }

    void test_sort_1(vector<int> data) {
        auto start = chrono::system_clock::now();
        result = new vector<int>(quick_sort(data));
        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - start;
        cout << endl << "Time: " << diff.count() << " s Result:" << endl;
        
    }

    void test_sort_2(vector<int>* data_ptr) {
        auto start = chrono::system_clock::now();
        vector<int>* result_vector = quick_sort2(data_ptr);
        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - start;
        cout << endl << "Time: " << diff.count() << " s Result:" << endl;
    }

    void test_sort_3(vector<int> data) {
        auto start = chrono::system_clock::now();
        unique_ptr<vector<int>> data_uniq_ptr = make_unique<vector<int>>(data);
        unique_ptr<vector<int>> result_u_p = quick_sort_multithreading(move(data_uniq_ptr));
        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - start;
        cout << endl << "Time: " << diff.count() << " s Result:" << endl;

        for_each(result_u_p->begin(), result_u_p->end(), [](int n) {cout << n << " "; });
    }

    ~Tester() {
        delete(data);
        delete(result);
    }



};

int main()
{   
    const int VECTOR_SIZE = 150;
    Tester tester;
    tester.prepare_test_vector(VECTOR_SIZE);
    tester.print_vector(*tester.data);
    //tester.test_sort_1(*tester.data);
    tester.test_sort_3(*tester.data);
    //tester.print_vector(*tester.result);
 
}




