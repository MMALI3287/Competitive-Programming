#include <iostream>
using namespace std;

int main()
{
    long long int n, m, a, s, i = 1, j = 1, l;
    cin >> n >> m >> a;
    cout << (((n + a - 1) / a) * ((m + a - 1) / a));
    return 0;
}