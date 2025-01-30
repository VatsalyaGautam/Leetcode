#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        vector<int> suffixMax(n);
        suffixMax[n - 1] = height[n - 1];
        
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }
        
        for (int i = 1; i < height.size() - 1; i++) {
            if (height[i] < prefixMax[i] && height[i] < suffixMax[i]) {
                total += min(prefixMax[i], suffixMax[i]) - height[i];
            }
        }
        return total;
    }
};

// Driver program
int main() {
    Solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = sol.trap(height);
    
    cout << result << endl;
    return 0;
}