#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        int cnt = 0;
        while (n != 0)
        {
            if ((n & 1) == 1)
            {
                cnt++;
            }
            n = n >> 1;
            if (cnt == 2)
                break;
        }
        return (cnt == 1);
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int testVal;

    cout << "Enter a number: ";
    cin >> testVal;

    if (solution.isPowerOfTwo(testVal))
    {
        cout << testVal << " is a power of two." << endl;
    }
    else
    {
        cout << testVal << " is not a power of two." << endl;
    }

    return 0;
}