#include <iostream>
using namespace std;
// A is the starting tower, B is the auxillary and C is the destination tower.
void towerOfHanoi(int n, int A = 1, int B = 2, int C = 3)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, A, C, B);
    cout << A << " " << C << endl;
    towerOfHanoi(n - 1, B, A, C);
}
int main()
{
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    towerOfHanoi(n);

    return 0;
}