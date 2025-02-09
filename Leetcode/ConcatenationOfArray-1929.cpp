#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int k = nums.size();
        vector<int> ans(2 * k);
        for (int i = 0; i < k; ++i)
        {
            ans[i] = nums[i];
            ans[i + k] = nums[i];
        }
        return ans;
    }
};

void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    Solution solution;
    vector<int> test1 = {1, 2, 3};
    vector<int> result1 = solution.getConcatenation(test1);
    cout << "Test 1: ";
    printVector(result1);

    vector<int> test2 = {4, 5, 6, 7};
    vector<int> result2 = solution.getConcatenation(test2);
    cout << "Test 2: ";
    printVector(result2);

    vector<int> test3 = {8, 9};
    vector<int> result3 = solution.getConcatenation(test3);
    cout << "Test 3: ";
    printVector(result3);

    return 0;
}