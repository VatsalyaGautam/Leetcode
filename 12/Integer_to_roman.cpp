#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int n = num;
        string r = "";
        while (n > 0) {
            if (n >= 1000) { r += 'M'; n -= 1000; }
            else if (n >= 900) { r += "CM"; n -= 900; }
            else if (n >= 500) { r += 'D'; n -= 500; }
            else if (n >= 400) { r += "CD"; n -= 400; }
            else if (n >= 100) { r += 'C'; n -= 100; }
            else if (n >= 90) { r += "XC"; n -= 90; }
            else if (n >= 50) { r += 'L'; n -= 50; }
            else if (n >= 40) { r += "XL"; n -= 40; }
            else if (n >= 10) { r += 'X'; n -= 10; }
            else if (n >= 9) { r += "IX"; n -= 9; }
            else if (n >= 5) { r += 'V'; n -= 5; }
            else if (n >= 4) { r += "IV"; n -= 4; }
            else if (n >= 1) { r += 'I'; n -= 1; }
        }
        return r;
    }
};

// Driver program to test the solution
int main() {
    Solution sol;
    cout << sol.intToRoman(1994) << endl;
    return 0;
}
