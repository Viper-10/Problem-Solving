#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1)
            cout << 2 << endl;

        else
            cout << ceil(n / 3) << endl;
    }

    return 0;
}