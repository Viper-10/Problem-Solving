#include <iostream>
#include <vector>
#define N 8
#define QUEEN 'Q'
#define FREE '.'
using namespace std;
string board[N];
bool checkFreeFromAttack(int row, int col)
{
    // previous rows, same column
    for (int i = row - 1; i >= 0; --i)
    {
        if (board[i][col] == QUEEN)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == QUEEN)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j)
    {
        if (board[i][j] == QUEEN)
        {
            return false;
        }
    }

    return true;
}
int dfs(int row)
{

    if (row == N)
        return 1;

    int ans = 0;
    for (int col = 0; col < N; ++col)
    {
        if (board[row][col] == FREE && checkFreeFromAttack(row, col))
        {
            board[row][col] = QUEEN;
            ans += dfs(row + 1);
            board[row][col] = FREE;
        }
    }

    return ans;
}
int main()
{
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        if (board[0][i] == FREE)
        {
            board[0][i] = QUEEN;
            ans += dfs(1);
            board[0][i] = FREE;
        }
    }

    cout << ans << endl;

    return 0;
}