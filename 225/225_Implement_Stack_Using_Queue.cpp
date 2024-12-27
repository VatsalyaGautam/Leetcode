#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    void push(int x) {
        if (q.empty()) {
            q.push(x);
            return;
        } else {
            q.push(x);
            for (int i = 0; i < q.size() - 1; i++) {
                int a = q.front();
                q.pop();
                q.push(a);
            }
        }
    }

    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

// Driver program
int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    cout << "Top element: " << obj->top() << endl; // Output: 3
    cout << "Pop element: " << obj->pop() << endl; // Output: 3
    cout << "Top element after pop: " << obj->top() << endl; // Output: 2
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Output: No
    return 0;
}