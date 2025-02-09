#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int result1 = sol.removeElement(nums1, val1);
    printf("Test case 1 - Expected: 2, Got: %d\n", result1);
    cout << "Array after removing element: ";
    for (int i = 0; result1; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int result2 = sol.removeElement(nums2, val2);
    printf("Test case 2 - Expected: 5, Got: %d\n", result2);
    cout << "Array after removing element: ";
    for (int i = 0; result2; i++)
    {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}