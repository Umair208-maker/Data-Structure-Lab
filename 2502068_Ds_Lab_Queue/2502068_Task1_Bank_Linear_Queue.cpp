#include <iostream>
using namespace std;

const int SIZE = 5;

class LinearQueue {
    int items[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int token) {
        if (isFull()) {
            cout << "Queue overflow! Cannot add " << token << endl;
            return;
        }
        if (front == -1)
            front = 0;
        items[++rear] = token;
        cout << "Customer " << token << " joined the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! No customer to serve." << endl;
            return;
        }
        cout << "Serving customer: " << items[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No waiting customers." << endl;
            return;
        }
        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++)
            cout << items[i] << " ";
        cout << endl;
    }

    int count() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    LinearQueue bank;
    bank.enqueue(101);
    bank.enqueue(102);
    bank.enqueue(103);
    bank.display();
    cout << "Waiting count: " << bank.count() << endl;
    bank.dequeue();
    bank.display();
    cout << "Waiting count: " << bank.count() << endl;
    return 0;
}
