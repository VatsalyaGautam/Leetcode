#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= target) {
                count++;
            }
        }
        return count;
    }
};

// Driver program
int main() {
    Solution solution;
    vector<int> hours = {8, 10, 5, 7, 9};
    int target = 8;
    cout << solution.numberOfEmployeesWhoMetTarget(hours, target) << endl;
    return 0;
}