#ifndef library
#define library
#include "../incluLibrary.hpp"
#endif
using namespace std;

void bouble() {
  cout << "boubleSort, ";
  vector<int> a;
  readFile(a);

  ofstream out;
  out.open("./sort/boubleSort/out.txt");

  if (out.fail()) {
    cout << "Fail To Write on out.txt";
    exit(1);
  }

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size() - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
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
}
// int main() {
//   bouble();
// }