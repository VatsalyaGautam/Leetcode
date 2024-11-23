#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].find(x) != string::npos)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Driver Program
int main()
{
    Solution sol;
    int n;
    cin >> n; // Number of words
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i]; // Input words
    }
    char x;
    cin >> x; // Character to search for
    vector<int> result = sol.findWordsContaining(words, x);
    for (int idx : result)
    {
        cout << idx << " "; // Output indices of words containing the character
    }
    cout << endl;
    return 0;
}