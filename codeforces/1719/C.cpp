#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> wins(n, 0);
        vector<int> strengths(n, 0);

        int prev = 0, prevIndex = 0;
        cin >> prev;
        strengths[0] = prev;

        for (int i = 1; i < n; ++i)
        {
            int a;
            cin >> a;

            if (prev < a)
            {
                wins[prevIndex] = i - prevIndex - (prevIndex == 0);
                prev = a;
                prevIndex = i;
            }

            strengths[i] = a;
        }

        wins[prevIndex] = INT32_MAX;

        while (q--)
        {
            int id, rounds;
            cin >> id >> rounds;
            id--;

            if (rounds < id || wins[id] <= 0)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << min(wins[id], rounds - id + (id != 0)) << endl;
            }
        }
    }

    return 0;
}