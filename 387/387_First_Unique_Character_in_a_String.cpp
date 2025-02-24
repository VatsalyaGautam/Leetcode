#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mpp[s[i]] == 1) return i;
        }
        return -1;
    }
};

// Driver Program
int main() {
    Solution sol;
    vector<string> testCases = {"leetcode", "loveleetcode", "aabb"};

    for (const string& s : testCases) {
        cout << "Input: " << s << " -> Output: " << sol.firstUniqChar(s) << endl;
    }

    return 0;
}