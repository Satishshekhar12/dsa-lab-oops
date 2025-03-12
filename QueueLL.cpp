#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node *front, *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        if (!rear) front = rear = newNode;
        else rear = rear->next = newNode;
        cout << val << " enqueued.\n";
    }

    void pop() {
        if (!front) cout << "Queue is empty.\n";
        else {
            Node* temp = front;
            front = front->next;
            if (!front) rear = nullptr;
            cout << temp->data << " dequeued.\n";
            delete temp;
        }
    }

    int getFront() { return front ? front->data : (cout << "Queue is empty.\n", -1); }
    int getRear()  { return rear  ? rear->data  : (cout << "Queue is empty.\n", -1); }
    bool isEmpty() { return !front; }
    
    ~Queue() { while (!isEmpty()) pop(); }
};

int main() {
    Queue q;
    int choice, value;
    while (true) {
        cout << "\n1.Push 2.Pop 3.Front 4.Rear 5.Empty? 6.Exit\nChoice: ";
        cin >> choice;
        if (choice == 6) break;
        switch (choice) {
            case 1: cin >> value, q.push(value); break;
            case 2: q.pop(); break;
            case 3: cout << "Front: " << q.getFront() << endl; break;
            case 4: cout << "Rear: " << q.getRear() << endl; break;
            case 5: cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            default: cout << "Invalid choice!\n";
        }
    }
}
