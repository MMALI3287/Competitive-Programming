#include <iostream>
#include <stack>
#include <string_view>
using namespace std;

class Solution
{
public:
    bool isValid(string_view str)
    {
        stack<char> s;
        for (char c : str)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                s.push(c);
                continue;
            }
            if (s.empty() ||
                (c == ')' && s.top() != '(') ||
                (c == '}' && s.top() != '{') ||
                (c == ']' && s.top() != '['))
                return false;
            s.pop();
        }
        return s.empty();
    }
};

void testIsValid(Solution &solution, const string &testStr, bool expected)
{
    bool result = solution.isValid(testStr);
    cout << "Test with input \"" << testStr << "\": "
         << (result == expected ? "Passed" : "Failed") << endl;
}

int main()
{
    Solution solution;
    testIsValid(solution, "()", true);
    testIsValid(solution, "()[]{}", true);
    testIsValid(solution, "(]", false);
    testIsValid(solution, "([)]", false);
    testIsValid(solution, "{[]}", true);
    return 0;
}