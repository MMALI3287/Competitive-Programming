#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, white = 0, blue = 0;

        for (auto i : nums)
        {
            if (i == 0)
                red++;
            else if (i == 1)
                white++;
            else
                blue++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < red)
                nums[i] = 0;
            else if (i < red + white)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}