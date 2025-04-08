#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

void heapify(vector<int> &a, int n, int i, unsigned long long int &swapCounter) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && a[largest] < a[left]) {
    largest = left;
  }
  if (right < n && a[largest] < a[right]) {
    largest = right;
  }

  if (largest != i) {
    swap(a[largest], a[i]);
    swapCounter++;
    heapify(a, n, largest, swapCounter);
  }
}

void heapSort(vector<int> &a, unsigned long long int &swapCounter) {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i, swapCounter);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(a[i], a[0]);
    swapCounter++;
    heapify(a, i, 0, swapCounter);
  }
}

unsigned long long int heap() {
  unsigned long long int swapCounter = 0;
  cout << "heapSort, ";
  ofstream out;
  out.open("./sort/HeapSort/out.txt");
  if (out.fail()) {
    cout << "無法寫入文件 out.txt";
    exit(1);
  }

  vector<int> a;
  readFile(a);

  heapSort(a, swapCounter);

  int count = 10;
  for (int i = 0; i < a.size(); i++) {
    if (printOut)
      cout << a[i] << ", ";
    out << a[i] << " ";
    if (count-- <= 0) {
      out << endl;
      count = 10;
    }
  }
  return swapCounter;
}

// int main() {
//   heap();
//   return 0;
// }
