#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        for (size_t i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                address.replace(i, 1, "[.]");
                i += 2;
            }
        }
        return address;
    }
};

// Driver program to test the solution
int main()
{
    Solution solution;
    string address;

    cout << "Enter the IP address: ";
    cin >> address;

    string result = solution.defangIPaddr(address);
    cout << "Defanged IP address: " << result << endl;

    return 0;
}