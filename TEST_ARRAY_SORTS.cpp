/*
* Testing class for the all sorts
*/

#include "ARRAY_SORTS.h"
#include "MULTITHREAD_SORT_TEMPLATES.h"
#include "MERGE_SORTS_SIMPLE_CPP.h"
#include "QUICK_SORT_PRIMITIVE_ARRAY_TEMPLATES_RECURSIVE.h"
#include "MERGE_SORT_ITERATIVE_PRIMITIVE_ARRAY_T.h"

class Tester {
public:
	vector<int>* data;
	
	Tester() : data(nullptr) {}

	void prepare_test_vector(int vector_size) {

		data = new vector<int>(vector_size);

		knuth_b generator;
		generator.seed(unsigned int(time(nullptr)));
		generate(data->begin(), data->end(), [&generator] {return generator() % 100;});

		cout << "Source:" << endl;
		for_each(data->begin(), data->end(), [](int n) {cout << n << " "; });
		cout << endl;
	}

	void test_sort_1() {
		
		vector<int> test_vector(*data);

		auto start = chrono::system_clock::now();
		quick_sort(test_vector);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Stack allocated QuickSort Time: " 
			<< diff.count() << " s Result:" << endl;
		print_vector(&test_vector);
	}

	void test_sort_2() {
		
		vector<int>* test_vector = new vector<int>();
		copy(data->begin(), data->end(), back_inserter(*test_vector));

		auto start = chrono::system_clock::now();
		quick_sort_heap(test_vector);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Heap allocated QuickSort Time: " 
			<< diff.count() << " s Result:" << endl;
		print_vector(test_vector);
		delete(test_vector);
	}
	
	void test_sort_3() {
		
		unique_ptr<vector<int>> data_uniq_ptr = make_unique<vector<int>>();
		copy(data->begin(), data->end(), back_inserter(*data_uniq_ptr));

		auto start = chrono::system_clock::now();
		unique_ptr<vector<int>> result_u_p = quick_sort_multithreading(move(data_uniq_ptr));
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Multithread QuickSort Time: "
			<< diff.count() << " s Result:" << endl;
		for_each(result_u_p->begin(), result_u_p->end(), [](int n) {cout << n << " "; });
	}
	
	void test_sort_5() {
		
		vector<int> test_vector(*data);// Copying data vector for inplace merging

		auto start = chrono::system_clock::now();
		merge_sort_inplace(test_vector.begin(), test_vector.end());
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "CPP recursive inplace_merge sort: "
			<< diff.count() << " s Result:" << endl;
		print_vector(&test_vector);
	}

	void test_sort_6() {
		
		vector<int> test_vector(*data);// Copying data vector for inplace merging

		auto start = chrono::system_clock::now();
		merge_sort(test_vector);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "CPP simple recursive MergeSort: "
			<< diff.count() << " s Result:" << endl;
		print_vector(&test_vector);
	}

	void test_sort_7() {
		vector<int> test_vector(*data);

		auto start = chrono::system_clock::now();
		sort(test_vector.begin(), test_vector.end());
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "CPP inner sort for vectors: "
			<< diff.count() << " s Result:" << endl;
		print_vector(&test_vector);
	}

	void test_sort_8() {
		
		size_t size = data->size();
		int* test_array = new int[size];
		for (size_t i = 0; i < size; i++) test_array[i] = (*data)[i];
		
		auto start = chrono::system_clock::now();
		quick_sort_prim(test_array, size);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Primitive int array resursive QuickSort: "
			<< diff.count() << " s Result:" << endl;

		print_array(test_array, size);
		delete[](test_array);
	}

	void test_sort_9() {
		size_t size = data->size();
		int* test_array = new int[size];
		for (size_t i = 0; i < size; i++) test_array[i] = (*data)[i];

		auto start = chrono::system_clock::now();
		quick_sort_prim_t(test_array, size);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Primitive T array resursive QuickSort: "
			<< diff.count() << " s Result:" << endl;

		print_array(test_array, size);
		delete[](test_array);
	}

	void test_sort_10() {
		size_t size = data->size();
		int* test_array = new int[size];
		for (size_t i = 0; i < size; i++) test_array[i] = (*data)[i];

		auto start = chrono::system_clock::now();
		merge_sort_iterative_prim_t(test_array, size);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Primitive T array iterative MergeSort: "
			<< diff.count() << " s Result:" << endl;

		print_array(test_array, size);
		delete[](test_array);
	}

	void print_vector(vector<int>* data) {	
		for_each(data->begin(), data->end(),
			[](int n) { cout << n << " "; });
		cout << endl;
	}

	void print_array(int* data, size_t size) {		
		for (size_t i = 0; i < size; i++) cout << data[i] << " ";
		cout << endl;
	}

	~Tester() {
		delete(data);
	}
};

int main()
{
	Tester tester;
	tester.prepare_test_vector(VECTOR_SIZE);

	tester.test_sort_1();
	
	tester.test_sort_2();
	
	tester.test_sort_3();
	
	tester.test_sort_5();
	
	tester.test_sort_6();
	
	tester.test_sort_7();
	
	tester.test_sort_8();
	
	tester.test_sort_9();
	
	tester.test_sort_10();
	
}




