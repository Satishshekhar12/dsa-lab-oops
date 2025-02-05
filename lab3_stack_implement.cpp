#include <iostream>
using namespace std;

#define MAX 10  // Define stack size

class stack {
    int arr[MAX]; 
    int top;  

public:
    stack() { top = -1; }  // Constructor to initialize top

    void push(int x) {
        if (top >= MAX - 1) {  // Prevent overflow
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Popped element is: " << arr[top--] << endl;
    }

    int topp() {
        if (top == -1) {
            cout << "Stack is empty, cannot fetch top element" << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

int main() {
    int op, x;
    stack st;

    cout << "Hello coder!" << endl;

    while (true) {
        cout << "Enter 1 to push, 2 to pop, 3 to get top, 4 to get size, 5 to exit: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> x;
                st.push(x);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout << "Top element: " << st.topp() << endl;
                break;
            case 4:
                cout << "Current stack size: " << st.size() << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Enter a valid input (1-5)." << endl;
        }
    }
}
