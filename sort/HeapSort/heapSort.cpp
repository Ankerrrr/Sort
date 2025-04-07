#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

void heapify(vector<int> &a, int n, int i) {
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
    heapify(a, n, largest);
  }
}

void heapSort(vector<int> &a) {
  int n = a.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(a, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(a[i], a[0]);
    heapify(a, i, 0);
  }
}

void heap() {
  cout << "heapSort, ";
  ofstream out;
  out.open("./sort/HeapSort/out.txt");
  if (out.fail()) {
    cout << "無法寫入文件 out.txt";
    exit(1);
  }

  vector<int> a;
  readFile(a);

  heapSort(a);

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
}

// int main() {
//   heap();
//   return 0;
// }
