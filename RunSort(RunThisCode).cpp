#include "./resource/generateTestDat.hpp"
#include "sort/HeapSort/heapSort.cpp"
#include "sort/boubleSort/boubleSort.cpp"
#include "sort/insertionSort/insertionSort.cpp"
#include "sort/mergeSort/mergeSort.cpp"
#include "sort/quickSort/quickSort.cpp"
#include "sort/selectionSort/selectionSort.cpp"

#include <chrono>
using namespace std;
using namespace std::chrono;

#define testCase 100000
#define testRange 10000
#define loop 1

void recordTime(vector<double> &time, void (*func)()) {
  auto start = high_resolution_clock::now();
  func();
  auto end = high_resolution_clock::now();

  double duration = duration_cast<microseconds>(end - start).count() / 1000.0;
  time.push_back(duration);
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

int main() {
  vector<double> heapSortTime, boubleSortTime, inserSortTime,
      mergeSortTime, quickSortTime, selectionSortTime, warnUp;

  for (int i = 0; i < loop; i++) {
    generate(testCase, 10000);
    recordTime(warnUp, heap);
    recordTime(heapSortTime, heap);
    recordTime(boubleSortTime, bouble);
    recordTime(inserSortTime, inser);
    recordTime(mergeSortTime, mergeS);
    recordTime(quickSortTime, qs);
    recordTime(selectionSortTime, selectionSort);
    cout << endl;
  }

  cout << "---- Sorting Time Summary (ms) ----" << endl;
  cout << "Info : testCase = " << testCase << ", testRange = " << testRange << ", Loop = " << loop << endl;
  cout << "Heap Sort: Avg = " << averageTime(heapSortTime) << ", Max = " << worstTime(heapSortTime) << endl;
  cout << "Bubble Sort: Avg = " << averageTime(boubleSortTime) << ", Max = " << worstTime(boubleSortTime) << endl;
  cout << "Insertion Sort: Avg = " << averageTime(inserSortTime) << ", Max = " << worstTime(inserSortTime) << endl;
  cout << "Merge Sort: Avg = " << averageTime(mergeSortTime) << ", Max = " << worstTime(mergeSortTime) << endl;
  cout << "Quick Sort: Avg = " << averageTime(quickSortTime) << ", Max = " << worstTime(quickSortTime) << endl;
  cout << "Selection Sort: Avg = " << averageTime(selectionSortTime) << ", Max = " << worstTime(selectionSortTime) << endl;
}