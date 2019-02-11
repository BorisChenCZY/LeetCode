#include <iostream>

using namespace std;
inline bool XOR(int a, int b)
{
  return (a < 0) ^ (b < 0);
}
int main()
{
  cout << (true ^ true) << endl;
  cout << (true ^ false) << endl;
  cout << (false ^ true) << endl;
  cout << (false ^ false) << endl;
  return 0;
}
