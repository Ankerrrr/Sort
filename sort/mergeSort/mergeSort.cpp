#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

void merge(vector<int> &arr, int lo, int mid, int hi) {
  vector<int> left(arr.begin() + lo, arr.begin() + mid + 1);
  vector<int> right(arr.begin() + mid + 1, arr.begin() + hi + 1);

  int i = 0, j = 0, k = lo;
  while (i < left.size() && j < right.size()) {
    if (left[i] < right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }
  while (i < left.size()) {
    arr[k++] = left[i++];
  }
  while (j < right.size()) {
    arr[k++] = right[j++];
  }
}

void mergeSort(vector<int> &arr, int lo, int hi) {
  if (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
  }
}

void mergeS() {
  cout << "mergeSort, ";
  ofstream out;
  out.open("./sort/mergeSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }

  vector<int> a;
  readFile(a);

  mergeSort(a, 0, a.size() - 1);

  int count = outlf;
  for (int i = 0; i < a.size(); i++) {
    if (printOut)
      cout << a[i] << ", ";
    out << a[i] << " ";
    if (count-- <= 0) {
      out << endl;
      count = outlf;
    }
  }
}

// int main() {
//   mergeS();
// }
