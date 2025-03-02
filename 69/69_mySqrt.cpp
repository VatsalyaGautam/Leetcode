#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int l = 1, r = x;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long mid_squared = mid * mid;
            if (mid_squared <= x && (mid + 1) * (mid + 1) > x)
                return mid;
            if (mid_squared > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return 0;
    }
};

// Driver program to test the solution
int main() {
    Solution sol;
    cout << sol.mySqrt(8) << endl;
    cout << sol.mySqrt(16) << endl;
    cout << sol.mySqrt(25) << endl;
    return 0;
}