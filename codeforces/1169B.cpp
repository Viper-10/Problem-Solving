#include <iostream>
#include <vector>
using namespace std;
bool check(vector<pair<int, int>> &pairs, int x, int y, int i)
{
  for (i = i + 1; i < pairs.size(); ++i)
  {
    if (!(pairs[i].first == x || pairs[i].first == y || pairs[i].second == x || pairs[i].second == y))
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int n, m;

  cin >> n >> m;

  vector<pair<int, int>> pairs(m);

  for (int i = 0; i < m; ++i)
  {
    cin >> pairs[i].first >> pairs[i].second;
  }

  for (int i = 0; i < 2; ++i)
  {
    int x = i == 0 ? pairs[0].first : pairs[0].second;
    bool pairWithoutX = false;

    for (int j = 1; j < m; ++j)
    {
      if (pairs[j].first != x && pairs[j].second != x)
      {
        pairWithoutX = true;

        if (check(pairs, x, pairs[j].first, j) || check(pairs, x, pairs[j].second, j))
        {
          cout << "YES" << endl;
          return 0;
        }
        else
          break;
      }
    }

    if (pairWithoutX == false)
    {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}