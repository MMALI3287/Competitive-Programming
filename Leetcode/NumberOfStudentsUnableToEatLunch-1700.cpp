#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            while (!students.empty() && !sandwiches.empty() &&
                   find(students.begin(), students.end(), sandwiches[0]) !=
                       students.end()) {
                if (students[0] == sandwiches[0]) {
                    sandwiches.erase(sandwiches.begin());
                    students.erase(students.begin());
                } else {
                    students.push_back(students[0]);
                    students.erase(students.begin());
                }
            }
            return students.size();
        }
};

// Added main function with complex tests.
int main() {
    Solution sol;
    
    {
        // Test 1: Expected output is 0.
        vector<int> students = {1, 1, 0, 0};
        vector<int> sandwiches = {0, 1, 0, 1};
        int result = sol.countStudents(students, sandwiches);
        cout << "Test 1 result: " << result << " (expected 0)" << endl;
    }
    
    {
        // Test 2: Expected output is 1.
        vector<int> students = {1, 1, 1, 0, 0, 1};
        vector<int> sandwiches = {1, 0, 0, 1, 1, 0};
        int result = sol.countStudents(students, sandwiches);
        cout << "Test 2 result: " << result << " (expected 1)" << endl;
    }
    
    {
        // Test 3: No one can eat; expected output is 3.
        vector<int> students = {0, 0, 0};
        vector<int> sandwiches = {1, 1, 1};
        int result = sol.countStudents(students, sandwiches);
        cout << "Test 3 result: " << result << " (expected 3)" << endl;
    }
    
    return 0;
}