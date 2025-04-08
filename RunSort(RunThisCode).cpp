#include "./resource/generateTestDat.hpp"
#include "sort/HeapSort/heapSort.cpp"
#include "sort/STL/STL_Sort.cpp"
#include "sort/boubleSort/boubleSort.cpp"
#include "sort/insertionSort/insertionSort.cpp"
#include "sort/mergeSort/mergeSort.cpp"
#include "sort/quickSort/quickSort.cpp"
#include "sort/selectionSort/selectionSort.cpp"

#include <chrono>
using namespace std;
using namespace std::chrono;

#define testCase 100000
#define testRange 5000
#define loop 1

void recordTime(vector<double> &time, vector<unsigned long long int> &count, unsigned long long int (*func)()) {
  auto start = high_resolution_clock::now();
  int swapCounter = func();
  auto end = high_resolution_clock::now();

  double duration = duration_cast<microseconds>(end - start).count() / 1000.0;
  time.push_back(duration);
  count.push_back(swapCounter);
}

double worstTime(const vector<double> &v) {
  double longestTime = 0.0;
  for (double i : v) {
    if (i > longestTime)
      longestTime = i;
  }
  return longestTime;
}

double averageTime(const vector<double> &v) {
  double sum = 0;
  for (double i : v) {
    sum += i;
  }
  return sum / v.size();
}

unsigned int long long hiCount(const vector<unsigned long long int> &v) {
  unsigned int long long hi = 0;
  for (int i : v) {
    if (i > hi) {
      hi = i;
    }
  }
  return hi;
}

int main() {
  vector<double> heapSortTime, boubleSortTime, inserSortTime,
      mergeSortTime, quickSortTime, selectionSortTime, STLSortTime, warnUp;
  vector<unsigned long long int> heapSortCount, boubleSortCount, inserSortCount,
      mergeSortCount, quickSortCount, selectionSortCount, warnUpC;
  ;

  for (int i = 0; i < loop; i++) {
    generate(testCase, 10000);
    recordTime(warnUp, warnUpC, heap);
    recordTime(heapSortTime, heapSortCount, heap);
    recordTime(boubleSortTime, boubleSortCount, bouble);
    recordTime(inserSortTime, inserSortCount, inser);
    recordTime(mergeSortTime, mergeSortCount, mergeS);
    recordTime(quickSortTime, quickSortCount, qs);
    recordTime(selectionSortTime, selectionSortCount, selectionSort);
    recordTime(STLSortTime, warnUpC, STLsort);
    cout << endl;
  }

  cout << "---- Sorting Time Summary (ms) ----" << endl;
  cout << "Info : testCase = " << testCase << ", testRange = " << testRange << ", Loop = " << loop << endl;
  cout << "Heap Sort:      Avg =" << averageTime(heapSortTime) << ", Max = " << worstTime(heapSortTime) << ", SwapCountHiggest = " << hiCount(heapSortCount) << endl;
  cout << "Bubble Sort:    Avg =" << averageTime(boubleSortTime) << ", Max = " << worstTime(boubleSortTime) << ", SwapCountHiggest = " << hiCount(boubleSortCount) << endl;
  cout << "Insertion Sort: Avg =" << averageTime(inserSortTime) << ", Max = " << worstTime(inserSortTime) << ", SwapCountHiggest = " << hiCount(inserSortCount) << endl;
  cout << "Merge Sort:     Avg =" << averageTime(mergeSortTime) << ", Max = " << worstTime(mergeSortTime) << ", SwapCountHiggest = " << hiCount(mergeSortCount) << endl;
  cout << "Quick Sort:     Avg =" << averageTime(quickSortTime) << ", Max = " << worstTime(quickSortTime) << ", SwapCountHiggest = " << hiCount(quickSortCount) << endl;
  cout << "Selection Sort: Avg =" << averageTime(selectionSortTime) << ", Max = " << worstTime(selectionSortTime) << ", SwapCountHiggest = " << hiCount(selectionSortCount) << endl;
  cout << "STL Sort:       Avg =" << averageTime(STLSortTime) << ", Max = " << worstTime(STLSortTime) << endl;
}