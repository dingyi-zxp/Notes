#include "complex.h"
#include <iostream>
#include <ostream>
using namespace std;

ostream &operator<<(ostream &os, const complex &x) {
  return os << '(' << real(x) << ',' << imag(x) << ')';
}
int main() {
  complex c1(1, 2);
  complex c2(2, 1);
  complex c3;
  c3 += c2;
  cout << c1 << c1 + c2 << c3;
  return 0;
}
