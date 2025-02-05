#include <iostream>
using namespace std;

class queue {
    int arr[4];  
    int start = -1;
    int end = -1;
    int size = 4;
    int curr_size = 0;  

public:
    void push(int val) {
        if (curr_size == size) {
            cout << "Queue full" << endl;
            return;
        }
        if (curr_size == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        arr[end] = val;
        curr_size++;
    }

    void pop() {
        if (curr_size == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Popped element is " << arr[start] << endl;
        if (curr_size == 1) {
            start = end = -1; // Reset queue
        } else {
            start = (start + 1) % size;
        }
        curr_size--;
    }

    int top() {
        if (curr_size == 0) {
            cout << "Queue empty, cannot fetch front element" << endl;
            return -1;
        }
        return arr[start];
    }

    int get_size() {
        return curr_size;
    }
};

int main() {
    int flag = 1;
    int op, x;
    queue q;

    cout << "Hello coder" << endl;

    while (flag) {
        cout << "Enter 1 for push, 2 for pop, 3 for front, 4 for size, and 5 for exit" << endl;
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
                cout << "Front element: " << q.top() << endl;
                break;
            case 4:
                cout << "Size is " << q.get_size() << endl;
                break;
            case 5:
                flag = 0;
                break;
            default:
                cout << "Enter a valid input" << endl;
        }
    }
    return 0;
}
