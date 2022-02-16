class Solution
{
public:
  int romanToInt(string &s)
  {
    int i = 0;
    int ans = 0;
    unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    while (i < s.size())
    {
      if (i + 1 < s.size() &&
          (s[i] == 'I' && (s[i + 1] == 'X' || s[i + 1] == 'V') ||
           s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C') ||
           s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')))
      {
        ans += m[s[i + 1]] - m[s[i]];
        i += 2;
      }

      else
      {
        ans += m[s[i]];
        i++;
      }
    }

    return ans;
  }
};