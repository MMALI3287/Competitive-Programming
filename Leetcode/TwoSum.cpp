#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> vec;
            if (!nums.empty()) {
                int rem;
                for (int i = 0; i < nums.size(); i++) {
                    rem = target - nums[i];
                    auto it = find(nums.begin(), nums.end(), rem);
                    if (it != nums.end()) {
                        auto jt = distance(nums.begin(), it);
                        if (i == jt)
                            continue;
                        vec.push_back(i);
                        vec.push_back(jt);
                        return vec;
                    }
                }
            }
            return vec;
        }
};

void testTwoSum() {
    Solution sol;
    {
        // Test 1
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        cout << "Input: [2, 7, 11, 15], Target: " << target << "\n";
        cout << "Expected: [0, 1] or [1, 0]\n";
        vector<int> result = sol.twoSum(nums, target);
        cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
        assert((result[0] == 0 && result[1] == 1) || (result[0] == 1 && result[1] == 0));
        cout << "Test 1 passed.\n";
    }
    {
        // Test 2
        vector<int> nums = {3, 2, 4};
        int target = 6;
        cout << "Input: [3, 2, 4], Target: " << target << "\n";
        cout << "Expected: [1, 2] or [2, 1]\n";
        vector<int> result = sol.twoSum(nums, target);
        cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
        assert((result[0] == 1 && result[1] == 2) || (result[0] == 2 && result[1] == 1));
        cout << "Test 2 passed.\n";
    }
    {
        // Test 3
        vector<int> nums = {3, 3};
        int target = 6;
        cout << "Input: [3, 3], Target: " << target << "\n";
        cout << "Expected: indices for the two elements\n";
        vector<int> result = sol.twoSum(nums, target);
        if (!result.empty()) {
            cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
        } else {
            cout << "Output: []\n";
        }
        assert(result.size() == 2);
        cout << "Test 3 passed.\n";
    }
}

int main() {
    testTwoSum();
    std::cout << "All tests passed.\n";
    return 0;
}