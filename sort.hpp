#ifndef SORT_HPP
#define SORT_HPP

#include <iterator>
#include <algorithm>

// Zadanie 2.2: Sortowanie przez wstawianie
template<typename Iterator>
void insertsort(Iterator first, Iterator last)
{
    if (first == last) {
        return;
    }

    for (Iterator i = std::next(first); i != last; ++i) {
        auto key = *i;
        Iterator j = i;

        while (j != first && key < *std::prev(j)) {
            *j = *std::prev(j);
            --j;
        }

        *j = key;
    }
}

// Zadanie 2.5: Sortowanie przez scalanie
template<typename Iterator>
void mergesort(Iterator first, Iterator last)
{
    auto distance = std::distance(first, last);

    if (distance < 2) {
        return;
    }

    Iterator mid = first;
    std::advance(mid, distance / 2);

    mergesort(first, mid);
    mergesort(mid, last);

    std::inplace_merge(first, mid, last);
}

#endif