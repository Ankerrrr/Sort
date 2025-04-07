#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

int partition(vector<int> &arr, int lo, int hi) {
  int pivotIndex = (hi + lo) / 2;

  swap(arr[pivotIndex], arr[hi]);
  int i = lo - 1;
  for (int j = lo; j < hi; j++) {
    if (arr[j] < arr[hi]) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[hi]);
  return i + 1;
}

void quickSort(vector<int> &arr, int lo, int hi) {
  if (lo < hi) {
    int p = partition(arr, lo, hi);
    quickSort(arr, lo, p - 1);
    quickSort(arr, p + 1, hi);
  }
}

void qs() {
  cout << "QuickSort, ";
  ofstream out;
  out.open("./sort/quickSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }

  vector<int> a;
  readFile(a);

  quickSort(a, 0, a.size() - 1);

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
//   qs();
// }
