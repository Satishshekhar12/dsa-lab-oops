#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Push (Insert at top)
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top; // New node points to the old top
        top = newNode;       // Update top to the new node
        cout << val << " pushed to stack.\n";
    }

    // Pop (Remove from top)
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->next; // Move top to the next node
        cout << temp->data << " popped from stack.\n";
        delete temp; // Free memory
    }

    // Peek (Get top element)
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display the stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function with menu-driven interface
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n***** Stack Menu *****\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5:
                s.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

//output sample
/* ***** Stack Menu *****
1. Push
2. Pop
3. Peek
4. Check if Empty
5. Display
6. Exit
Enter your choice: 1
Enter value to push: 10
10 pushed to stack.

***** Stack Menu *****
Enter your choice: 1
Enter value to push: 20
20 pushed to stack.

***** Stack Menu *****
Enter your choice: 1
Enter value to push: 30
30 pushed to stack.

***** Stack Menu *****
Enter your choice: 5
Stack elements: 30 20 10 

***** Stack Menu *****
Enter your choice: 3
Top element: 30

***** Stack Menu *****
Enter your choice: 2
30 popped from stack.

***** Stack Menu *****
Enter your choice: 5
Stack elements: 20 10 

***** Stack Menu *****
Enter your choice: 4
Stack is not empty.

***** Stack Menu *****
Enter your choice: 2
20 popped from stack.

***** Stack Menu *****
Enter your choice: 2
10 popped from stack.

***** Stack Menu *****
Enter your choice: 4
Stack is empty.

***** Stack Menu *****
Enter your choice: 5
Stack is empty.

***** Stack Menu *****
Enter your choice: 6
Exiting program.
*/
