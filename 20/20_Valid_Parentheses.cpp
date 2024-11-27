#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if ((ch == ')' || ch == ']' || ch == '}') && st.empty()) {
                return false;
            } else if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if ((ch == ')' && st.top() == '(') || 
                       (ch == ']' && st.top() == '[') || 
                       (ch == '}' && st.top() == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};

// Driver program
int main() {
    Solution solution;
    vector<string> testCases = {"()", "()[]{}", "(]", "([)]", "{[]}"};
    for (const auto& testCase : testCases) {
        cout << "Input: " << testCase << " => Output: " 
             << (solution.isValid(testCase) ? "true" : "false") << endl;
    }
    return 0;
}