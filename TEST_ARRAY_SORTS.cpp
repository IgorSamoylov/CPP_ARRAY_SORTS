#include "ARRAY_SORTS.h"
#include "MULTITHREAD_SORT_TEMPLATES.h"
#include "CPP_INNER_IMPLEMENTATIONS.h"

class Tester {
public:
	vector<int>* data;
	
	Tester() : data(nullptr) {}

	void prepare_test_vector(int vector_size) {

		data = new vector<int>(vector_size);

		knuth_b generator;
		generator.seed(time(nullptr));
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

		for_each(test_vector.begin(), test_vector.end(), [](int n) {cout << n << " "; });

	}

	void test_sort_2() {

		vector<int>* test_vector = new vector<int>(*data);

		auto start = chrono::system_clock::now();
		quick_sort2(test_vector);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Heap allocated QuickSort Time: " 
			<< diff.count() << " s Result:" << endl;

		for_each(test_vector->begin(), test_vector->end(), [](int n) {cout << n << " "; });
	}
	
	void test_sort_3() {
		
		unique_ptr<vector<int>> data_uniq_ptr = make_unique<vector<int>>(*data);

		auto start = chrono::system_clock::now();
		unique_ptr<vector<int>> result_u_p = quick_sort_multithreading(move(data_uniq_ptr));
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Multithread QuickSort Time: "
			<< diff.count() << " s Result:" << endl;

		for_each(result_u_p->begin(), result_u_p->end(), [](int n) {cout << n << " "; });
	}
	/*
	void test_sort_4(vector<int>& data) {
		
		unique_ptr<vector<int>> data_uniq_ptr = make_unique<vector<int>>(data);

		auto start = chrono::system_clock::now();
		unique_ptr<vector<int>> result_u_p = quick_sort_multithreading_T(move(data_uniq_ptr));
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Multithread Template QuickSort Time: "
			<< diff.count() << " s Result:" << endl;

		for_each(result_u_p->begin(), result_u_p->end(), [](int n) {cout << n << " "; });
	}
	*/
	

	void test_sort_5() {

		vector<int> test_vector(*data);// Copying data vector for inplace merging

		auto start = chrono::system_clock::now();
		merge_sort_inplace(test_vector.begin(), test_vector.end());
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "CPP inplace_merge sort: "
			<< diff.count() << " s Result:" << endl;

		for_each(test_vector.begin(), test_vector.end(), [](int n) {cout << n << " "; });
	}

	void test_sort_6() {

		vector<int> test_vector(*data);// Copying data vector for inplace merging

		auto start = chrono::system_clock::now();
		merge_sort(test_vector);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "CPP simple merge sort: "
			<< diff.count() << " s Result:" << endl;

		for_each(test_vector.begin(), test_vector.end(), [](int n) {cout << n << " "; });
	}

	void test_sort_7() {

		vector<int> test_vector(*data);

		auto start = chrono::system_clock::now();
		sort(test_vector.begin(), test_vector.end());
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "CPP inner sort: "
			<< diff.count() << " s Result:" << endl;

		for_each(test_vector.begin(), test_vector.end(), [](int n) {cout << n << " "; });
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
	//tester.test_sort_4();
	tester.test_sort_5();
	tester.test_sort_6();
	tester.test_sort_7();
	

}




