#include <iostream>
#include <vector>
using namespace std;
void print(int a, int b, int n)
{
    while (b <= n)
    {
        cout << a << " " << b << endl;
        a += 4;
        b += 4;
    }
}
int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        k %= 4;
        if (k == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else
            cout << "YES" << endl;

        int numberWithModulo1 = 1, numberWithModulo2 = 2;
        int numberWithModulo3 = 3, numberWithModulo0 = 4;

        if (k == 1 || k == 3)
        {
            print(numberWithModulo1, numberWithModulo2, n);
        }
        else
        {
            print(numberWithModulo2, numberWithModulo1, n);
        }

        print(numberWithModulo3, numberWithModulo0, n);
    }

    return 0;
}