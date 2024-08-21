#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        st.insert(nums.begin(), nums.end());
        nums.clear(); // Clear the original array
        nums.insert(nums.begin(), st.begin(), st.end());
        return st.size();
    }
};

int main()
{
    vector<int> nums = {1, 1, 2}; // Example input
    Solution solution;
    int k = solution.removeDuplicates(nums); // Calls the solution function

    // Output the results
    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}