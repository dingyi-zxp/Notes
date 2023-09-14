#include "String.h"
#include <iostream>

using namespace std;

int main() {
  String s1("Hello");
  String *s2 = new String("World");

  String s3;
  cout << s1 << *s2 << s3;

  s3 = *s2;
  cout << s3;
  s3 = s1;
  cout << s3;
  return 0;
}
