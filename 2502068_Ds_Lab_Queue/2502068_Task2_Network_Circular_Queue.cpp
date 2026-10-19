#include <iostream>
using namespace std;

const int SIZE = 3;

class CircularQueue {
    int packets[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void enqueue(int id) {
        if (isFull()) {
            cout << "Buffer full! Packet " << id
                 << " cannot be added." << endl;
            return;
        }
        rear = (rear + 1) % SIZE;
        packets[rear] = id;
        count++;
        cout << "Packet " << id << " added." << endl;
    }

    void transmit() {
        if (isEmpty()) {
            cout << "Buffer empty! No packet to transmit." << endl;
            return;
        }
        cout << "Transmitting packet: " << packets[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packets waiting." << endl;
            return;
        }
        cout << "Packets waiting: ";
        for (int i = 0; i < count; i++)
            cout << packets[(front + i) % SIZE] << " ";
        cout << endl;
    }
};

int main() {
    CircularQueue network;
    network.enqueue(201);
    network.enqueue(202);
    network.enqueue(203);
    network.display();
    network.transmit();
    network.enqueue(204); 
    network.display();
    return 0;
}
