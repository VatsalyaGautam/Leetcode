#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long total_chalk = 0;
        int students = chalk.size();
        for (int i = 0; i < students; i++)
        {
            total_chalk += chalk[i];
        }

        k = k % total_chalk;

        for (int i = 0; i < students; i++)
        {
            if (k < chalk[i])
            {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> chalk1 = {5, 1, 5};
    int k1 = 22;
    cout << "Test case 1: Student who will replace the chalk = " << solution.chalkReplacer(chalk1, k1) << endl;

    // Test case 2
    vector<int> chalk2 = {3, 4, 1, 2};
    int k2 = 25;
    cout << "Test case 2: Student who will replace the chalk = " << solution.chalkReplacer(chalk2, k2) << endl;

    // Test case 3
    vector<int> chalk3 = {1, 1, 1, 1};
    int k3 = 7;
    cout << "Test case 3: Student who will replace the chalk = " << solution.chalkReplacer(chalk3, k3) << endl;

    // Test case 4
    vector<int> chalk4 = {10};
    int k4 = 100;
    cout << "Test case 4: Student who will replace the chalk = " << solution.chalkReplacer(chalk4, k4) << endl;

    return 0;
}