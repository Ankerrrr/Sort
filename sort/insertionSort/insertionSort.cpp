// check from left to right
// if small then now check then move to left and check if small then left again
#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

unsigned long long int inser() {
  unsigned long long int swapCounter = 0;
  cout << "insertionSort, ";
  ofstream out;
  out.open("./sort/insertionSort/out.txt");
  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }
  vector<int> a;
  readFile(a);

  // for (int i = 0; i < a.size(); i++) {
  //   cout << a[i] << ", ";
  // }
  // cout << endl;
  for (int i = 1; i < a.size(); i++) {
    int k = i;
    while (a[k - 1] > a[k] && k != 0) {
      int temp = a[k - 1];
      a[k - 1] = a[k];
      a[k] = temp;
      swapCounter++;
      k--;
    }
  }

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
  return swapCounter;
}
