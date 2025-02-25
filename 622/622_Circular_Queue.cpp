#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> vec;
    int rear, front, k;

    MyCircularQueue(int k) {
        this->k = k;
        vec.resize(k);
        front = -1;
        rear = -1;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % k;
        }
        vec[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        if (front == rear) {  
            front = rear = -1;
        } else {
            front = (front + 1) % k;
        }
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : vec[front];
    }

    int Rear() {
        return isEmpty() ? -1 : vec[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % k == front;
    }
};

// Driver program
int main() {
    MyCircularQueue q(3);

    cout << q.enQueue(1) << endl;  
    cout << q.enQueue(2) << endl;  
    cout << q.enQueue(3) << endl;  
    cout << q.enQueue(4) << endl;  
    cout << q.Rear() << endl;      
    cout << q.isFull() << endl;    
    cout << q.deQueue() << endl;   
    cout << q.enQueue(4) << endl;  
    cout << q.Rear() << endl;      

    return 0;
}