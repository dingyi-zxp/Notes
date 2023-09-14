#include <iostream>

using namespace std;

class CDoucument {
public:
  void OnFileOpen() {
    cout << "OnFileOpen" << endl;
    Serialize();
  }

  virtual void Serialize() { cout << "CDoucument" << endl; };
};

class CMyDoc : public CDoucument {
public:
  virtual void Serialize() { cout << "CMyDoc" << endl; }
};
int main(int argc, char *argv[]) {
  CMyDoc myDoc;
  myDoc.OnFileOpen();
  return 0;
}
