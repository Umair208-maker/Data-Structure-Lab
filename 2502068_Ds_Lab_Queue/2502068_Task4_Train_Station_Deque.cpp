#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
    int items[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque full! Cannot insert at front." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        items[front] = id;
        count++;
        cout << "Inserted " << id << " at front." << endl;
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque full! Cannot insert at rear." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        items[rear] = id;
        count++;
        cout << "Inserted " << id << " at rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque empty! Nothing to remove." << endl;
            return;
        }
        cout << "Removed from front: " << items[front] << endl;
        if (count == 1) front = rear = -1;
        else front = (front + 1) % SIZE;
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque empty! Nothing to remove." << endl;
            return;
        }
        cout << "Removed from rear: " << items[rear] << endl;
        if (count == 1) front = rear = -1;
        else rear = (rear - 1 + SIZE) % SIZE;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No passenger requests." << endl;
            return;
        }
        cout << "Deque (front to rear): ";
        for (int i = 0; i < count; i++)
            cout << items[(front + i) % SIZE] << " ";
        cout << endl;
    }
};

int main() {
    Deque station;
    station.insertRear(301);
    station.insertRear(302);
    station.insertFront(300);
    station.display();
    station.deleteFront();
    station.deleteRear();
    station.display();
    return 0;
}
