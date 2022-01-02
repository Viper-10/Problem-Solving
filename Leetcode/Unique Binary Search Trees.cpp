class Solution
{
public:
  int numTrees(int n)
  {
    // return numTrees(1, n);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
      for (int j = i - 1, k = 0; j >= 0; --j, ++k)
      {
        dp[i] += dp[j] * dp[k];
      }
    }

    return dp[n];
  }

private:
  int dp[20] = {0};

  int numTrees(int start, int end)
  {

    if (start > end)
    {
      return 1;
    }

    if (dp[end - start] != 0)
    {
      return dp[end - start];
    }

    int ans = 0;

    for (int i = start; i <= end; ++i)
    {
      int ans1 = numTrees(start, i - 1);
      int ans2 = numTrees(i + 1, end);

      ans += ans1 * ans2;
    }

    dp[end - start] = ans;
    return ans;
  }
};