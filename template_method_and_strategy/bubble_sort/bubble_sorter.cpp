#include <bubble_sorter.h>

BubbleSorter::BubbleSorter() : m_operations(0), m_length(0) {}

int BubbleSorter::doSort() {
    m_operations = 0;

    if (m_length <= 1) {
        return m_operations;
    }

    for (int nextToLast = m_length - 2; nextToLast >= 0; nextToLast--) {
        for (int index = 0; index <= nextToLast; index++) {
            if (outOfOrder(index)) {
                swap(index);
            }
            m_operations++;
        }
    }

    return m_operations;
}

void BubbleSorter::printSorted() {
    for (int i = 0; i < m_length; i++) {
        print(cout, i);
        cout << ", ";
    }
    cout << endl;
}
