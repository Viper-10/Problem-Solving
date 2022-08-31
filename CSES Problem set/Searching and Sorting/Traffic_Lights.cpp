#include <iostream>
#include <set>
using namespace std;
int main()
{
    int length, n;
    cin >> length >> n;

    set<int> position;
    multiset<int> distance;

    position.insert(0);
    position.insert(length);

    distance.insert(length);

    for (int i = 0; i < n; ++i)
    {
        int pos;
        cin >> pos;

        auto next = position.upper_bound(pos);
        auto prev = position.lower_bound(pos);

        prev--;
        int intervalLength = *next - *prev;

        distance.erase(distance.find(intervalLength));
        distance.insert(*next - pos);
        distance.insert(pos - *prev);

        position.insert(pos);

        cout << *distance.rbegin() << endl;
    }

    return 0;
}