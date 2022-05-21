#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check(long long ans)
{
    int flag1 = 0, flag2 = 0;
    long long sr = sqrt(ans);
    if (sr * sr == ans)
        flag1 = 1;
    int cube;
    for (int i; i <= ans; i++)
    {
        cube = i * i * i;
        if (cube == ans)
        {
            flag2 = 1;
        }
        else if (cube > ans)
        {
            break;
        }
    }
    if (flag1 == 1 && flag2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void testcase()
{
    static int case_num = 1;
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0, a = 0, b = 0; i < N; i++)
    {
        cin >> a >> b;
        ans += pow(a, b);
    }
    cout << ans << endl;
    int chck = check(ans);
    cout << "Case " << case_num++ << ": ";
    if (chck)
    {
        cout << "The number is both square and cube" << endl;
    }
    else
    {
        cout << "The number does not meet expectation" << endl;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        testcase();
    }
    return 0;
}