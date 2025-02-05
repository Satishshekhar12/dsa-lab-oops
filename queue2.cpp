#include <iostream>
using namespace std;

#define MAX 4  

class Queue {
    int queue[MAX];  
    int start;       
    int end;         
    int curr_size;   

public:
    Queue() {
        start = -1;
        end = -1;
        curr_size = 0;
    }

    void push(int val) {
        if (curr_size == MAX) {
            cout << "Queue is full" << endl;
            return;
        }
        if (curr_size == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % MAX;
        }
        queue[end] = val;
        curr_size++;
    }

    void pop() {
        if (curr_size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int el = queue[start];
        if (curr_size == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % MAX;
        }
        curr_size--;
        cout << "Popped element: " << el << endl;
    }

    int top() {
        if (curr_size == 0) {
            cout << "Queue is empty, no top element" << endl;
            return -1;
        }
        return queue[start];
    }

    int size() {
        return curr_size;
    }
};

int main() {
    Queue q;
    int op, x;

    cout << "Hello coder!" << endl;

    while (true) {
        cout << "Enter 1 to push, 2 to pop, 3 to get top, 4 to get size, 5 to exit: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> x;
                q.push(x);
                break;
            case 2:
                q.pop();
                break;
            case 3:
                cout << "Top element: " << q.top() << endl;
                break;
            case 4:
                cout << "Current queue size: " << q.size() << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Enter a valid input (1-5)." << endl;
        }
    }
}
