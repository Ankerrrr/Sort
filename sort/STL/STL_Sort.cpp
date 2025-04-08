#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
#include <algorithm>
// move minimal to left
using namespace std;

unsigned long long int STLsort() {
  unsigned long long int swapCounter = 0;
  cout << "SelectionSort, ";
  ofstream out;
  out.open("./sort/STL/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
  }
  vector<int> a;
  readFile(a);

  sort(a.begin(), a.end());

  int count = outlf;
  for (int i = 0; i < a.size(); i++) {
    if (printOut)
      cout << a[i] << ",";
    out << a[i] << " ";
    if (count-- <= 0) {
      out << endl;
      count = outlf;
    }
  }
  out.close();
  return swapCounter;
}

// int main() {
//   selectionSort();
// }