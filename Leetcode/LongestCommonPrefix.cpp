class Solution
{
public:
  string longestCommonPrefix(vector<string> &str)
  {
    string ans = "";

    if (str.size() == 1)
      return str[0];

    for (int j = 0;; ++j)
    {
      for (int i = 1; i < str.size(); ++i)
      {
        if (j == str[i].size() || str[i][j] != str[i - 1][j])
        {
          return ans;
        }
      }

      ans += str[0][j];
    }

    return ans;
  }
};