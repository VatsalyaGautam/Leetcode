#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int n = operations.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (operations[i][1] == '+')
            {
                ans++;
                continue;
            }
            ans--;
        }
        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    vector<string> operations(n);
    cout << "Enter the operations (e.g., ++X, X++, --X, X--): " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> operations[i];
    }

    int result = solution.finalValueAfterOperations(operations);
    cout << "Final value after operations: " << result << endl;

    return 0;
}