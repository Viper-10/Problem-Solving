class Solution
{

  bool row[9][9];
  bool col[9][9];
  bool box[3][3][9];

public:
  Solution()
  {
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(box, false, sizeof(box));
  }

  bool isValidSudoku(vector<vector<char>> &board)
  {
    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        if (board[i][j] != '.')
        {
          int k = board[i][j] - '0';
          k -= 1;

          if (row[i][k] || col[j][k] || box[i / 3][j / 3][k])
          {
            return false;
          }

          row[i][k] = true;
          col[j][k] = true;
          box[i / 3][j / 3][k] = true;
        }
      }
    }

    return true;
  }
};