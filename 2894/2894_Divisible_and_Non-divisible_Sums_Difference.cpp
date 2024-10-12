#include <iostream>
using namespace std;

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m != 0)
                num1 += i;
            else
                num2 += i;
        }
        return num1 - num2;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    int n, m;

    cout << "Enter value of n: ";
    cin >> n;
    cout << "Enter value of m: ";
    cin >> m;

    int result = solution.differenceOfSums(n, m);
    cout << "Difference of sums: " << result << endl;

    return 0;
}