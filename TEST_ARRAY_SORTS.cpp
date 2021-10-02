#include "ARRAY_SORTS.h"

class Tester {
public:
	vector<int>* data;
	
	Tester() : data(nullptr) {}

	void prepare_test_vector(int vector_size) {
		data = new vector<int>(vector_size);

		knuth_b generator;
		generator.seed(time(nullptr));

		cout << "Source:" << endl;
		for (int i = 0; i < vector_size; i++) {
			int value = generator() % 100;
			(*data)[i] = value;
			cout << value << " ";
		}
		cout << endl;
	}

	void test_sort_1(vector<int> data) {

		auto start = chrono::system_clock::now();
		vector<int> result = quick_sort(data);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Stack allocated QuickSort Time: " 
			<< diff.count() << " s Result:" << endl;

		for_each(result.begin(), result.end(), [](int n) {cout << n << " "; });

	}

	void test_sort_2(vector<int>* data_ptr) {

		auto start = chrono::system_clock::now();
		vector<int>* result_vector = quick_sort2(data_ptr);
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Heap allocated QuickSort Time: " 
			<< diff.count() << " s Result:" << endl;

		for_each(result_vector->begin(), result_vector->end(), [](int n) {cout << n << " "; });
	}
	
	void test_sort_3(vector<int> data) {
		
		unique_ptr<vector<int>> data_uniq_ptr = make_unique<vector<int>>(data);

		auto start = chrono::system_clock::now();
		unique_ptr<vector<int>> result_u_p = quick_sort_multithreading(move(data_uniq_ptr));
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Multithread QuickSort Time: "
			<< diff.count() << " s Result:" << endl;

		for_each(result_u_p->begin(), result_u_p->end(), [](int n) {cout << n << " "; });
	}
	/*
	void test_sort_4(vector<int> data) {
		
		unique_ptr<vector<int>> data_uniq_ptr = make_unique<vector<int>>(data);

		auto start = chrono::system_clock::now();
		unique_ptr<vector<int>> result_u_p = quick_sort_multithreading_T<int>(move(data_uniq_ptr));
		auto end = chrono::system_clock::now();

		chrono::duration<double> diff = end - start;
		cout << endl << "Multithread Template QuickSort Time: "
			<< diff.count() << " s Result:" << endl;

		for_each(result_u_p->begin(), result_u_p->end(), [](int n) {cout << n << " "; });
	}
	*/


	~Tester() {
		delete(data);
	}
};

int main()
{
	
	Tester tester;
	tester.prepare_test_vector(VECTOR_SIZE);
	tester.test_sort_1(*tester.data);
	tester.test_sort_2(tester.data);
	tester.test_sort_3(*tester.data);
	//tester.test_sort_4(*tester.data);
	

}




