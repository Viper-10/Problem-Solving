#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s = "";
        int x = 9;

        while (n > 0)
        {
            if (n < x)
            {
                s += n + '0';
                break;
            }
            s += x + '0';
            n -= x;
            x--;
        }

        for (int i = s.length() - 1; i >= 0; --i)
        {
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}