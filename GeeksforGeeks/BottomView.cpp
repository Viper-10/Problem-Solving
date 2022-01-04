#include <iostream>
#include <map>
using namespace std;
int main()
{

  map<int, int> m;

  m.insert(make_pair(1, 5));
  m.insert(make_pair(2, 6));
  m[3] = 5;
  cout << m[3] << endl;
  cout << m[2] << endl;
  m[2] = 10;
  cout << m[2] << endl;

  return 0;
}