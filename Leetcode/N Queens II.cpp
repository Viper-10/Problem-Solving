class Solution
{
  bool check(vector<vector<bool>> matrix, int i, int j)
  {
    // same column
    for (int k = i - 1; k >= 0; --k)
    {
      if (matrix[k][j])
      {
        return false;
      }
    }

    for (int k = 1; j - k >= 0 && i - k >= 0; ++k)
    {
      if (matrix[i - k][j - k])
      {
        return false;
      }
    }

    for (int k = 1; i - k >= 0 && j + k < matrix.size(); ++k)
    {
      if (matrix[i - k][j + k])
      {
        return false;
      }
    }

    return true;
  }

  int totalNQueens(vector<vector<bool>> matrix, int n, int i = 1)
  {
    if (i == n)
    {
      return 1;
    }

    int ans = 0;

    for (int j = 0; j < n; ++j)
    {
      if (check(matrix, i, j))
      {
        matrix[i][j] = true;
        ans += totalNQueens(matrix, n, i + 1);
        matrix[i][j] = false;
      }
    }

    return ans;
  }

public:
  int totalNQueens(int n)
  {
    if (n == 1)
      return 1;

    if (n < 4)
      return 0;

    vector<vector<bool>> matrix(n, vector<bool>(n, 0));
    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
      matrix[0][i] = true;
      ans += totalNQueens(matrix, n);
      matrix[0][i] = false;
    }

    return ans;
  }
};