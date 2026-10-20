#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>
#include "sort.hpp"
#include <string>

// Pomocnicza funkcja do wypisywania kontenera na konsolę
template<typename T>
void print_collection(const T& container, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== DEMONSTRACJA ALGORYTMOW SORTOWANIA ===" << std::endl << std::endl;

    // Test 1: std::vector z algorytmem insertsort (wstawianie)
    std::vector<int> v1 = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};
    print_collection(v1, "Przed insertsort (vector)");
    insertsort(v1.begin(), v1.end());
    print_collection(v1, "Po   insertsort (vector)");
    assert(std::is_sorted(v1.begin(), v1.end()));
    std::cout << "----------------------------------------" << std::endl;

    // Test 2: std::vector z algorytmem mergesort (scalanie)
    std::vector<int> v2 = {9, 4, 7, 3, 6, 8, 2, 1, 5, 0};
    print_collection(v2, "Przed mergesort  (vector)");
    mergesort(v2.begin(), v2.end());
    print_collection(v2, "Po   mergesort  (vector)");
    assert(std::is_sorted(v2.begin(), v2.end()));
    std::cout << "----------------------------------------" << std::endl;

    // Test 3: std::array z mergesort
    std::array<int, 10> arr = {42, 12, 5, 67, 23, 1, 9, 33, 14, 8};
    print_collection(arr, "Przed mergesort  (array) ");
    mergesort(arr.begin(), arr.end());
    print_collection(arr, "Po   mergesort  (array) ");
    assert(std::is_sorted(arr.begin(), arr.end()));
    std::cout << "----------------------------------------" << std::endl;

    // Test 4: Zwykła tablica C z insertsort
    int raw_arr[] = {15, 3, 9, 7, 1, 12};
    size_t raw_size = sizeof(raw_arr) / sizeof(*raw_arr);
    
    std::cout << "Przed insertsort (tablica C): ";
    for (size_t i = 0; i < raw_size; ++i) {
        std::cout << raw_arr[i] << " ";
    }
    std::cout << std::endl;

    insertsort(raw_arr, raw_arr + raw_size);

    std::cout << "Po   insertsort (tablica C): ";
    for (size_t i = 0; i < raw_size; ++i) {
        std::cout << raw_arr[i] << " ";
    }
    std::cout << std::endl;
    
    assert(std::is_sorted(raw_arr, raw_arr + raw_size));

    std::cout << std::endl << "Wszystkie testy zakonczone sukcesem!" << std::endl;

    return 0;
}

  