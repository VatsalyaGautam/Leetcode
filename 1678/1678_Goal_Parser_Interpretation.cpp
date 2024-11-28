#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                ans.append("G");
            } else if (command[i + 1] == 'a') {
                ans.append("al");
                i += 3;
            } else {
                ans.append("o");
                i += 1;
            }
        }
        return ans;
    }
};

// Driver program
int main() {
    Solution solution;
    string command;
    cin >> command; // Input the command string
    cout << solution.interpret(command) << endl;
    return 0;
}