#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 1, 2};
    int result1 = sol.removeDuplicates(nums1);
    printf("Test case 1 - Expected: 2, Got: %d\n", result1);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result1; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result2 = sol.removeDuplicates(nums2);
    printf("Test case 2 - Expected: 5, Got: %d\n", result2);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result2; i++)
    {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}
