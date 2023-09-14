#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char p[] = "Hello";
  char *q = p;
  cout << p << strlen(p) << q;
  return 0;
}
