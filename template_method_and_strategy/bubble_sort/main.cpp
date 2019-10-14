#include <int_bubble_sorter.h>
#include <double_bubble_sorter.h>

int main() {
    vector<int> intVec{5, 2, 1, 3, 4};
    vector<double> doubleVec{5.0, 2.0, 1.0, 3.0, 4.0};

    IntBubbleSorter ibs;
    ibs.sort(intVec);
    ibs.printSorted();

    DoubleBubbleSorter dbs;
    dbs.sort(doubleVec);
    dbs.printSorted();

    return 0;
}
