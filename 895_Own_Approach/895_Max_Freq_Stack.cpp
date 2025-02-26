#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    vector<int> vec;
    unordered_map<int, pair<int, vector<int>>> mpp;
    int i;
    int maxFreq;
    FreqStack() {
        i = 0;
        maxFreq = 0;
    }

    void push(int val) {
        vec.push_back(val);
        mpp[val].first++;
        if (maxFreq < mpp[val].first) {
            maxFreq = mpp[val].first;
        }
        mpp[val].second.push_back(i);
        i++;
    }

    int pop() {
        int temp = -1;
        int ans = -1;
        for (auto it : mpp) {
            if (it.second.first == maxFreq && it.second.second[it.second.second.size() - 1] > temp) {
                temp = it.second.second[it.second.second.size() - 1];
                ans = it.first;
            }
        }
        mpp[ans].first--;
        mpp[ans].second.pop_back();
        maxFreq = 0;
        for (auto it : mpp) {
            if (maxFreq < it.second.first) {
                maxFreq = it.second.first;
            }
        }

        auto rit = find(vec.rbegin(), vec.rend(), ans);
        if (rit != vec.rend()) {
            vec.erase(next(rit).base());
        }

        return ans;
    }
};

// Driver Program
int main() {
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << fs.pop() << "\n";  // 5
    cout << fs.pop() << "\n";  // 7
    cout << fs.pop() << "\n";  // 5
    cout << fs.pop() << "\n";  // 4

    return 0;
}