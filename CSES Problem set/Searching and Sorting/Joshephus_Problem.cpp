#include <iostream>
#include <set>
using namespace std;
set<int> s;
bool deleteInIntervalsOf2(set<int>::iterator start)
{
    for (auto it = start; it != s.end(); it++)
    {
        cout << *it << " ";
        auto hold = it;

        it++;
        s.erase(hold);

        if (it == s.end())
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        s.insert(i);

    bool startFromIndex2 = true;

    do
    {
        auto start = s.begin();
        if (startFromIndex2)
            start++;
        startFromIndex2 = deleteInIntervalsOf2(start);

    } while (!s.empty());

    return 0;
}