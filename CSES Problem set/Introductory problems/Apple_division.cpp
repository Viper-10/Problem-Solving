#include <iostream>
using namespace std;
int64_t n;
int arr[20];
int64_t groupA, groupB, ans = INT64_MAX;
void solve(int index = 0)
{
    if (index == n)
    {
        ans = min(ans, abs(groupA - groupB));
        return;
    }

    groupA += arr[index];
    solve(index + 1);

    groupA -= arr[index];
    groupB += arr[index];

    solve(index + 1);
    groupB -= arr[index];
}
int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    solve();

    return 0;
}