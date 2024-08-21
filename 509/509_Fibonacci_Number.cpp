#include <iostream>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main()
{
    Solution sol;

    // Test cases
    int test_cases[] = {0, 1, 2, 3, 4, 5, 10, 20}; // Add more test cases as needed
    for (int n : test_cases)
    {
        cout << "fib(" << n << ") = " << sol.fib(n) << endl;
    }

    return 0;
}