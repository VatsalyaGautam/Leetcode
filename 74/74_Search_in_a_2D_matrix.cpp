#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n * m) - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int mid_row = mid / m;
            int mid_col = mid % m;
            if (matrix[mid_row][mid_col] == target)
            {
                return true;
            }
            else if (matrix[mid_row][mid_col] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};

// Driver code
int main()
{
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    int target = 3;
    cout << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;

    target = 13;
    cout << (sol.searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}