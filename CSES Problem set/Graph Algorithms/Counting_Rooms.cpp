#include <iostream>
#define floor '.'
#define wall '#'
using namespace std;
char **building;
bool **visited;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(int x, int y)
{
    visited[x][y] = true;
    for (int a = 0; a < 4; ++a)
    {
        int newX = x + dx[a], newY = y + dy[a];

        if (check(newX, newY) && !visited[newX][newY] && building[newX][newY] == floor)
        {
            dfs(newX, newY);
        }
    }
}
int main()
{
    cin >> n >> m;

    building = new char *[n];
    visited = new bool *[n];

    for (int i = 0; i < n; ++i)
    {
        building[i] = new char[m];
        visited[i] = new bool[m];
        for (int j = 0; j < m; ++j)
        {
            cin >> building[i][j];
            visited[i][j] = 0;
        }
    }

    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (building[i][j] == floor && !visited[i][j])
            {
                dfs(i, j);
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}