#include <iostream>
#include <stack>
#include <functional>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

void runTest(const string &testName, function<void()> test)
{
    cout << "Running " << testName << "... ";
    try
    {
        test();
        cout << "Passed!" << endl;
    }
    catch (const exception &e)
    {
        cout << "Failed: " << e.what() << endl;
    }
}

int main()
{
    // Test basic operations
    runTest("Basic Operations", []()
            {
        MinStack stack;
        stack.push(-2);
        stack.push(0);
        stack.push(-3);
        
        if (stack.getMin() != -3) throw runtime_error("Wrong minimum");
        stack.pop();
        if (stack.top() != 0) throw runtime_error("Wrong top");
        if (stack.getMin() != -2) throw runtime_error("Wrong minimum after pop"); });

    // Test empty stack
    runTest("Empty Stack", []()
            {
        MinStack stack;
        try {
            stack.top();
            throw runtime_error("Should throw on empty stack");
        } catch (const runtime_error&) {
            // Expected behavior
        } });

    // Test with duplicate values
    runTest("Duplicate Values", []()
            {
        MinStack stack;
        stack.push(1);
        stack.push(1);
        stack.push(1);
        if (stack.getMin() != 1) throw runtime_error("Wrong minimum with duplicates");
        stack.pop();
        if (stack.getMin() != 1) throw runtime_error("Wrong minimum after pop with duplicates"); });

    return 0;
}