#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        stack<int> s;
        unordered_set<int> set;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            s.push(a);
        }

        while (!s.empty() && set.find(s.top()) == set.end())
        {
            set.insert(s.top());
            s.pop();
        }

        cout << s.size() << endl;
    }
    return 0;
}