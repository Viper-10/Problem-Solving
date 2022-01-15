class Solution
{
  string s1, s2;
  int n, m;

  int recursion(int i = 0, int j = 0)
  {
    if (i == n || j == m)
      return 0;

    if (s1[i] == s2[j])
      return recursion(i + 1, j + 1) + 1;

    else
      return max(recursion(i + 1, j), recursion(i, j + 1));
  }

  int dp()
  {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= m; ++j)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }

        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[n][m];
  }

public:
  int longestCommonSubsequence(string &s1, string &s2)
  {
    this->s1 = s1;
    this->s2 = s2;
    this->n = s1.size();
    this->m = s2.size();
    // return recursion();
    return dp();
  }
};