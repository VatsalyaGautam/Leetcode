#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    // Test cases
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = " ";
    string test4 = "No 'x' in Nixon";

    // Check and print results
    cout << "Test 1: " << (sol.isPalindrome(test1) ? "True" : "False") << endl;
    cout << "Test 2: " << (sol.isPalindrome(test2) ? "True" : "False") << endl;
    cout << "Test 3: " << (sol.isPalindrome(test3) ? "True" : "False") << endl;
    cout << "Test 4: " << (sol.isPalindrome(test4) ? "True" : "False") << endl;

    return 0;
}