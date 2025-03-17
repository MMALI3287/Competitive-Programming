#include <iostream>
using namespace std;

int main()
{
    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) // For w=2, can't divide into two positive even parts (smallest even number is 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}