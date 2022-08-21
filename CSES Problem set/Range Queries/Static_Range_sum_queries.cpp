#include <iostream>
using namespace std;
int main()
{
    int n, q;

    cin >> n >> q;

    int64_t *prefix = new int64_t[n + 1];

    prefix[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        prefix[i] = prefix[i - 1] + a;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}