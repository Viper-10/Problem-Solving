#include <bits/stdc++.h>

using namespace std;

int poisonousPlants(vector<int> &arr)
{
  int n = arr.size();

  stack<pair<int, int>> s;
  int ans = 0;

  s.push(make_pair(arr[n - 1], 0));

  for (int i = n - 2; i >= 0; --i)
  {
    int count = 0;
    while (!s.empty() && arr[i] < s.top().first)
    {
      count++;
      int topCount = s.top().second;

      count = max(topCount, count);

      s.pop();
    }
    ans = max(count, ans);

    s.push(make_pair(arr[i], count));
  }

  return ans;
}
int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  cout << poisonousPlants(arr) << endl;

  return 0;
}
