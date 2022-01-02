#include <unordered_set>
using namespace std;
class Solution
{
public:
  int findMaximumXOR(vector<int> &nums)
  {
    int ans = 0;

    for (int i = 30; i >= 0; --i)
    {
      unordered_set<int> s;
      int mask = mask | 1 << i;

      for (int j : nums)
      {
        int prefix = j & mask;
        s.insert(prefix);
      }

      int newAns = ans | 1 << i;

      for (int prefix : s)
      {
        if (s.count(newAns ^ prefix))
        {
          ans = newAns;
          break;
        }
      }
    }

    return ans;
  }
};