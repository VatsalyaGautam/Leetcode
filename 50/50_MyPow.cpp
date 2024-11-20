#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long num = n;
        double ans = 1.0;

        if (num < 0) {
            x = 1 / x;
            num = -num;
        }

        while (num > 0) {
            if (num % 2 == 1) {
                ans *= x;
            }
            x *= x;
            num /= 2;
        }

        return ans;
    }
};

// Driver Program
int main() {
    Solution sol;
    double x;
    int n;
    cin >> x >> n; // Example inputs
    cout << fixed << setprecision(5) << sol.myPow(x, n) << endl;
    return 0;
}