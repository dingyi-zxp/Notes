#include <iostream>

using namespace std;
class Account {
public:
  static double m_rate;
  static void set_rate(const double &rate) { m_rate = rate; }
  static double get_rate() { return m_rate; }
};
double Account::m_rate = 2.1;
int main() {
  cout << Account::get_rate() << ' ' << endl;
  Account::m_rate = 3;
  cout << Account::get_rate() << ' ' << endl;
  Account::set_rate(3.33);
  cout << Account::get_rate() << ' ' << endl;

  Account a1, a2;
  cout << a1.get_rate() << ' ' << a2.get_rate() << ' ' << endl;

  a1.set_rate(5);

  cout << a1.get_rate() << ' ' << a2.get_rate() << endl;
  return 0;
}
