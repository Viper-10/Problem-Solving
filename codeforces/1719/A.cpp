#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if ((n + m) % 2 == 0)
        {
            cout << "Tonya" << endl;
        }
        else
            cout << "Burenka" << endl;
    }

    return 0;
}