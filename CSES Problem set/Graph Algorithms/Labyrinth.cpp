#include <iostream>
#include <vector>
#include <queue>
#define FLOOR '.'
#define WALL '#'
#define START 'A'
#define END 'B'
using namespace std;
char **building;
bool **visited;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};
int minPathLength = INT32_MAX, currPathLength = 0;
vector<char> ans;
void bfs(int x, int y)
{
    queue<pair<int, int>> q;

    q.push({x, y});

    while (!q.empty())
    {
        
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

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (building[i][j] == START)
            {
                // dfs(i, j);
                bfs(i, j);
            }
        }
    }

    if (minPathLength == INT32_MAX)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << minPathLength << endl;

    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i];
    }

    cout << endl;
    return 0;
}