#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        string t;
        cin >> t;

        int n;
        cin >> n;

        string strings[10];

        int longestStringLength = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> strings[i];

            longestStringLength = max(longestStringLength, (int)strings[i].length());
        }

        int tLength = t.length();
        int ans[101][2];
        int ansIndex = 0;
        bool possible = true;
        int last = 0;
        do
        {
            bool found = false;

            for (int i = last; i >= 0; --i)
            {
                for (int len = longestStringLength; len >= 0; --len)
                {
                    string substring = t.substr(i, len);

                    for (int j = 0; j < n; ++j)
                    {
                        const string &s = strings[j];

                        if (s.length() == len && s == substring)
                        {
                            last = i + len;
                            found = true;
                            ans[ansIndex][0] = j;
                            ans[ansIndex][1] = i;
                            ansIndex++;
                            break;
                        }
                    }
                }

                if (found)
                    break;
            }

            if (!found)
            {
                cout << -1 << endl;
                possible = false;
                break;
            }

        } while (last < tLength);

        if (possible)
        {

            cout << ansIndex << endl;
            for (int i = 0; i < ansIndex; ++i)
            {
                cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << endl;
            }
        }

        delete[] strings;
    }

    return 0;
}