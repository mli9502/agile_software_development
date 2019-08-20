#ifndef INT_BUBBLE_SORTER_H
#define INT_BUBBLE_SORTER_H

#include <bubble_sorter.h>

class IntBubbleSorter : public BubbleSorter {
private:
    vector<int> m_array;

protected:
    void swap(int idx) override {
        int tmp = m_array[idx];
        m_array[idx] = m_array[idx + 1];
        m_array[idx + 1] = tmp;
    }

    bool outOfOrder(int idx) override {
        return (m_array[idx] > m_array[idx + 1]);
    }

    void print(ostream& os, int idx) override {
        os << to_string(m_array[idx]);
    }

public:
    IntBubbleSorter() = default;

    int sort(const vector<int>& array) {
        m_array = array;
        m_length = m_array.size();
        return doSort();
    }
};

#endif