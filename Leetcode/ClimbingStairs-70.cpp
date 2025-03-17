#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
        {
            return 1;
        }

        int prev1 = 1;
        int current = 1;

        for (int i = 2; i <= n; i++)
        {
            current = prev1 + current;
            prev1 = current - prev1;
        }

        return current;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    int result = sol.climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << result << endl;
    return 0;
}