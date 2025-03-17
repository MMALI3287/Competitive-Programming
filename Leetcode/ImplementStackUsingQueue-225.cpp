#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyStack {
    public:
        MyStack() {}
        deque<int> dq;
    
        void push(int x) { dq.push_back(x); }
    
        int pop() {
            int x = dq.back();
            dq.pop_back();
            return x;
        }
    
        int top() { return dq.back(); }
    
        bool empty() { return dq.empty(); }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */

int main(){
    MyStack s;
    cout << "Starting complex test of MyStack:" << "\n";
    
    // Test sequence 1: push several elements
    cout << "Pushing elements: 10, 20, 30, 40" << "\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Current top (expected 40): " << s.top() << "\n";

    // Test sequence 2: pop one element
    cout << "Pop element (expected 40): " << s.pop() << "\n";
    cout << "New top (expected 30): " << s.top() << "\n";

    // Test sequence 3: further operations
    cout << "Pushing elements: 50, 60" << "\n";
    s.push(50);
    s.push(60);
    cout << "Current top (expected 60): " << s.top() << "\n";

    // Test sequence 4: pop all elements
    cout << "Popping all elements:" << "\n";
    while (!s.empty()){
        cout << s.pop() << " ";
    }
    cout << "\nStack is now empty." << "\n";

    return 0;
}