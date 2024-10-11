#include <iostream>
using namespace std;

class Solution
{
public:
    int theMaximumAchievableX(int num, int t)
    {
        return num + (2 * t);
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int num, t;

    cout << "Enter the value of num: ";
    cin >> num;

    cout << "Enter the value of t: ";
    cin >> t;

    int result = solution.theMaximumAchievableX(num, t);
    cout << "The maximum achievable X is: " << result << endl;

    return 0;
}