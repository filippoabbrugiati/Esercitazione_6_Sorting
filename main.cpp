#include <cmath> // contiene floor
#include <iostream>
#include <numeric> // contiene iota
#include <sstream>
#include <chrono> // https://en.cppreference.com/w/cpp/chrono

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj {
    double value;
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { return lhs.value < rhs.value; }

int main(int argc, char *argv[])
{
    size_t m = 10000;  
	if (argc > 1) {
			istringstream convert(argv[1]);
			convert >> m;  
			cout << "Usato valore dimensione vettore: " << m << endl;
		} else {
			cerr << "Nessun argomento fornito. Usando il valore di default: " << m << endl;
		}
    vector<int> v1(m);  
    vector<double> v2(m);  
    vector<int> v3(m, 0);  

    
    srand(2);
    for (size_t i = 0; i < m; i++) {
        v2[i] = rand() / static_cast<double>(RAND_MAX);
    }

    
    for (size_t i = 0; i < m / 2; i++) {
        v3[i] = i;  
    }
    for (size_t i = m / 2; i < m; i++) {
        v3[i] = rand() % 1000;  
    }

    unsigned int num_experiment = 100;  

    
    double time_elapsed_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v1);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v1 /= num_experiment;
    cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << " microsecondi" << endl;

    
    double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++) {
        vector<double> v(v2);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;
    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << " microsecondi" << endl;

   
    double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v3);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;
    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << " microsecondi" << endl;

    
    double time_elapsed_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v1);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v1 /= num_experiment;
    cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << " microsecondi" << endl;

    
    double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++) {
        vector<double> v(v2);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;
    cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << " microsecondi" << endl;

    
    double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v3);
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;
    cout << "Heap Sort - v3: " << time_elapsed_heap_v3 << " microsecondi" << endl;

    return 0;
}

