#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, startHour, startMinute;
        cin >> n >> startHour >> startMinute;

        int ansHour = INT32_MAX, ansMinute = 0;

        for (int i = 0; i < n; ++i)
        {
            int h, m;
            cin >> h >> m;

            int currHour, currMinute;

            if (startHour > h || h == startHour && startMinute > m)
            {
                h += 24;
            }
            currHour = h - startHour;

            if (startMinute > m)
            {
                currHour--;
                currMinute = 60 - (startMinute - m);
            }
            else
            {
                currMinute = m - startMinute;
            }

            if (ansHour > currHour || ansHour == currHour && ansMinute > currMinute)
            {
                ansHour = currHour;
                ansMinute = currMinute;
            }
        }
        cout << ansHour << " " << ansMinute << endl;
    }

    return 0;
}