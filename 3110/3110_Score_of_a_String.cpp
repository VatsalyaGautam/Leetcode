#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            ans += abs((int)s[i - 1] - (int)s[i]);
        }
        return ans;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    int result = solution.scoreOfString(input);
    cout << "Score of the string is: " << result << endl;

    return 0;
}