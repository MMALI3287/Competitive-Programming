#include <iostream>
using namespace std;

int dominopiling(int n, int m)
{
    if (n == 1)
        return m;
    if (m == 1)
        return n;
    if (n == m)
        return n * 2;
    if (n > m)
        return dominopiling(n - 1, m) + 1;
    else
        return dominopiling(n, m - 1) + 1;
}

int main()
{
    int n, m;

    cin >> n >> m;
    cout << dominopiling(n, m);
    return 0;
}