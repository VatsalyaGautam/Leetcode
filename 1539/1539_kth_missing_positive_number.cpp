#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                k++;
        }
        return k;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Test case 1: The 5th missing positive number is " << solution.findKthPositive(arr1, k1) << endl;

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Test case 2: The 2nd missing positive number is " << solution.findKthPositive(arr2, k2) << endl;

    // Test case 3
    vector<int> arr3 = {5, 6, 7, 8, 9};
    int k3 = 9;
    cout << "Test case 3: The 9th missing positive number is " << solution.findKthPositive(arr3, k3) << endl;

    // Test case 4
    vector<int> arr4 = {1, 3, 5, 7};
    int k4 = 3;
    cout << "Test case 4: The 3rd missing positive number is " << solution.findKthPositive(arr4, k4) << endl;

    return 0;
}