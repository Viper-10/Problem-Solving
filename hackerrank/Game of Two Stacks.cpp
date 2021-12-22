#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int dp(int maxSum, vector<int> &a, vector<int> &b)
{
  int n = a.size(), m = b.size();
  int ans = 0;

  int64_t sum = 0;
  int i;

  for (i = 0; i < n; ++i)
  {
    sum += a[i];
    if (sum > maxSum)
    {
      sum -= a[i];
      break;
    }
    ans = i + 1;
  }
  i--;
  for (int j = 0; j < m; ++j)
  {
    while (i >= 0 && sum + b[j] > maxSum)
    {
      sum -= a[i];
      i--;
    }

    if (sum + b[j] > maxSum)
    {
      break;
    }

    sum += b[j];
    ans = max(ans, i + 1 + j + 1);
  }

  return ans;
}
int recursion(int currSum, vector<int> &a, vector<int> &b, int i = 0, int j = 0)
{
  if ((uint64_t)i == a.size() && (uint64_t)j == b.size())
  {
    return 0;
  }

  if (currSum < 0)
    return -1;

  int ans = -1;

  if ((uint64_t)i != a.size())
  {
    ans = recursion(currSum - a[i], a, b, i + 1, j);
  }

  if ((uint64_t)j != b.size())
  {
    ans = max(ans, recursion(currSum - b[j], a, b, i, j + 1));
  }

  return ans + 1;
}
int twoStacks(const int &maxSum, vector<int> &a, vector<int> &b)
{
  // return recursion(maxSum, a, b, log);
  return dp(maxSum, a, b);
}
int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, m, maxSum;

    cin >> n >> m >> maxSum;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < m; ++i)
      cin >> b[i];

    cout << twoStacks(maxSum, a, b) << endl;
  }
}
