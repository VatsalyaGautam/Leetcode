#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAllowed(string allowed, string word) {
        for (int i = 0; i < word.size(); i++) {
            if (allowed.find(word[i]) == string::npos) {
                return false;
            }
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            if (isAllowed(allowed, words[i])) {
                ans++;
            }
        }
        return ans;
    }
};

// Driver program
int main() {
    Solution solution;
    string allowed = "abc";
    vector<string> words = {"a", "b", "c", "ab", "ac", "bc", "abc"};
    cout << solution.countConsistentStrings(allowed, words) << endl;
    return 0;
}