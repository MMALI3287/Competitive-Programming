#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BrowserHistory {
    vector<string> history;
    int curr;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
    }

    void visit(string url) {
        history.resize(curr + 1);
        history.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }

    string forward(int steps) {
        curr = min((int)history.size() - 1, curr + steps);
        return history[curr];
    }
};

int main() {
    BrowserHistory browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    cout << browser.back(1) << "\n";      // Expected: facebook.com
    cout << browser.back(1) << "\n";      // Expected: google.com
    cout << browser.forward(1) << "\n";   // Expected: facebook.com
    browser.visit("linkedin.com");        // Clears forward history
    cout << browser.forward(2) << "\n";   // Expected: linkedin.com
    cout << browser.back(2) << "\n";      // Expected: google.com
    cout << browser.back(7) << "\n";      // Expected: leetcode.com
    return 0;
}