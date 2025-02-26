#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> temp;
    
    MyQueue() {}

    void push(int x) { 
        st.push(x); 
    }

    int pop() {
        if (st.empty()) return -1;
        
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        int ans = temp.top();
        temp.pop();
        
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
        return ans;
    }

    int peek() {
        if (st.empty()) return -1;
        
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        
        int ans = temp.top();
        
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
        return ans;
    }

    bool empty() { 
        return st.empty(); 
    }
};

// Driver Program
int main() {
    MyQueue* obj = new MyQueue();

    // Pushing elements into the queue
    obj->push(1);
    obj->push(2);
    obj->push(3);
    
    cout << "Front element (peek): " << obj->peek() << endl;  // Should print 1

    cout << "Popped: " << obj->pop() << endl;  // Should print 1
    cout << "Popped: " << obj->pop() << endl;  // Should print 2
    
    cout << "Front element (peek): " << obj->peek() << endl;  // Should print 3
    
    cout << "Queue empty? " << (obj->empty() ? "Yes" : "No") << endl;  // Should print No

    cout << "Popped: " << obj->pop() << endl;  // Should print 3
    cout << "Queue empty? " << (obj->empty() ? "Yes" : "No") << endl;  // Should print Yes

    delete obj;
    return 0;
}