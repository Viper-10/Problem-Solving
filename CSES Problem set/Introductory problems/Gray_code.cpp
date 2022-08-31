#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<string> output((1 << n));

    output[0] = "0";
    output[1] = "1";
    int prevSize = 2;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < prevSize; ++j)
        {
            output[j] += '0';
        }

        for (int j = prevSize - 1, k = prevSize; j >= 0; --j, k++)
        {
            output[k] = output[j].substr(0, output[j].length() - 1) + "1";
        }

        prevSize = 1 << i;
    }

    for (int i = 0; i < (1 << n); ++i)
    {
        reverse(output[i].begin(), output[i].end());
        cout << output[i] << endl;
    }

    return 0;
}