#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int maxAND(int *arr, int n)
  {
    int ans = 0;

    for (int i = 31; i >= 0; --i)
    {
      int mask = ans | 1 << i;
      int count = 0;
      // since we're checking for pair, count should atleast be 2
      for (int j = 0; j < n; ++j)
      {
        if ((arr[j] & mask) == mask)
        {
          count++;
        }
      }

      if (count > 1)
        ans = mask;
    }

    return ans;
  }
};
int main()
{
  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  Solution obj;

  cout << obj.maxAND(arr, n) << endl;

  return 0;
}