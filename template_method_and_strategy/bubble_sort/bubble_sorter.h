#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

#include <common_includes.h>

class BubbleSorter {
 private:
  int m_operations;

 protected:
  int m_length;

  int doSort();

  virtual void swap(int idx) = 0;
  virtual bool outOfOrder(int idx) = 0;

  virtual void print(ostream& os, int idx) = 0;

 public:
  BubbleSorter();

  void printSorted();

  virtual ~BubbleSorter() = default;
};

#endif

