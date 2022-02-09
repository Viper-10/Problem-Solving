class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    int ans = 0;

    for (int x : nums)
      m[x]++;

    for (auto &it : m)
    {
      int key = it.first, val = it.second;
      if (k == 0)
      {
        if (val > 1)
        {
          ans += 1;
        }
      }

      else if (m.count(key + k))
      {
        ans += 1;
      }
    }

    return ans;
  }
};