#pragma once

#include <iostream>
#include <vector>

namespace SortLibrary {


template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};


template<Sortable T>
void BubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    bool swapped;
    
    
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        
        
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        
        if (!swapped) {
            break;
        }
    }
}

// funzione per costruire un max heap
template<Sortable T>
void heapify(std::vector<T>& arr, int n, int i) {
    int largest = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2;  

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

 
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {

        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

} 
