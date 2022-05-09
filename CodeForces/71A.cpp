#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].length() <= 10)
        {
            cout << s[i] << endl;
        }
        else if (s[i].length() > 10)
        {
            cout << s[i].substr(0, 1) << s[i].length() - 2 << s[i].substr(s[i].length() - 1, s[i].length()) << endl;
        }
    }
    return 0;
}