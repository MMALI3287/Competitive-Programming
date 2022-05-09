#include <iostream>
using namespace std;

int main()
{
    int n, temp = 0;
    cin >> n;
    int x[n], y[n], z[n], a[n];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];
    for (int i = 0; i < n; i++)
    {
        if (x[i] + y[i] + z[i] >= 2)
            temp++;
    }
    cout << temp << endl;
    return 0;
}