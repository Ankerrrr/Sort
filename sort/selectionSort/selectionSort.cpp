#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
// move minimal to left
using namespace std;

unsigned long long int selectionSort() {
  unsigned long long int swapCounter = 0;
  cout << "SelectionSort, ";
  ofstream out;
  out.open("./sort/selectionSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
  }
  vector<int> a;
  readFile(a);
  // for (int i = 0; i < a.size(); i++) {
  //   cout << a[i] << ",";
  // }
  // cout << endl;
  for (int i = 0; i < a.size(); i++) {
    int min = a[i];
    for (int j = i; j < a.size(); j++) {
      if (a[j] < min) {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        min = a[i];
        swapCounter++;
      }
    }
  }
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