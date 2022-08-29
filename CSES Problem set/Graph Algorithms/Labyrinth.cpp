#include <iostream>
#define floor '.'
#define wall '#'
using namespace std;
char **building;
bool **visited;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
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
            if (building[i][j] == 'A' && !visited[i][j])
            {
            }
        }
    }

    cout << count << endl;
    return 0;
}