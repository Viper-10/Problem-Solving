class Solution
{
  bool row[9][10], col[9][10], box[3][3][10];

  bool solveSudoku(vector<vector<char>> &board, int i, int j)
  {
    if (i == 9)
      return true;

    if (j == 9)
      return solveSudoku(board, i + 1, 0);

    if (board[i][j] != '.')
    {
      return solveSudoku(board, i, j + 1);
    }

    for (int k = 1; k <= 9; ++k)
    {
      if (!row[i][k] && !col[j][k] && !box[i / 3][j / 3][k])
      {
        row[i][k] = col[j][k] = box[i / 3][j / 3][k] = true;

        board[i][j] = k + '0';

        if (solveSudoku(board, i, j + 1))
          return true;

        board[i][j] = '.';

        row[i][k] = col[j][k] = box[i / 3][j / 3][k] = false;
      }
    }

    return false;
  }

public:
  Solution()
  {
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));
  }

  void solveSudoku(vector<vector<char>> &board)
  {
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] == '.')
          continue;

        int k = board[i][j] - '0';

        row[i][k] = col[j][k] = box[i / 3][j / 3][k] = true;
      }
    }

    solveSudoku(board, 0, 0);
  }
};