#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) return n;
        else return n * 2;
    }
};

// Driver program
int main() {
    Solution solution;
    int n = 5;
    cout << solution.smallestEvenMultiple(n) << endl;
    return 0;
}