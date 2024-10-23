#include <iostream>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int ans = 0;
        while (start != 0 && goal != 0)
        {
            if ((start & 1) != (goal & 1))
                ans++;
            start = start >> 1;
            goal = goal >> 1;
        }
        while (start != 0)
        {
            if ((start & 1) != 0)
                ans++;
            start = start >> 1;
        }
        while (goal != 0)
        {
            if ((goal & 1) != 0)
                ans++;
            goal = goal >> 1;
        }
        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int start, goal;

    cout << "Enter start value: ";
    cin >> start;
    cout << "Enter goal value: ";
    cin >> goal;

    int result = solution.minBitFlips(start, goal);
    cout << "Minimum bit flips required: " << result << endl;

    return 0;
}