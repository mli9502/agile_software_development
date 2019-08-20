#ifndef DOUBLE_BUBBLE_SORTER_H
#define DOUBLE_BUBBLE_SORTER_H

#include <bubble_sorter.h>

class DoubleBubbleSorter : public BubbleSorter {
private:
    vector<double> m_array;

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
    DoubleBubbleSorter() = default;

    int sort(const vector<double>& array) {
        m_array = array;
        m_length = m_array.size();
        return doSort();
    }
};

#endif