#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

struct Patient {
    string id;
    int priority;
};

class PriorityQueue {
    Patient patients[SIZE];
    int count;

public:
    PriorityQueue() { count = 0; }

    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void enqueue(string id, int priority) {
        if (isFull()) {
            cout << "Queue full! Cannot add " << id << endl;
            return;
        }
        patients[count].id = id;
        patients[count].priority = priority;
        count++;
        cout << "Patient " << id << " added with priority "
             << priority << "." << endl;
    }

    void treatNext() {
        if (isEmpty()) {
            cout << "No patients waiting for treatment." << endl;
            return;
        }

        int highest = 0;
        for (int i = 1; i < count; i++) {
            if (patients[i].priority < patients[highest].priority)
                highest = i;
        }

        cout << "Treating patient: " << patients[highest].id
             << " (Priority " << patients[highest].priority
             << ")" << endl;

        for (int i = highest; i < count - 1; i++)
            patients[i] = patients[i + 1];
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patients in the queue." << endl;
            return;
        }
        cout << "Waiting patients (ID - Priority):" << endl;
        for (int i = 0; i < count; i++)
            cout << patients[i].id << " - "
                 << patients[i].priority << endl;
    }
};

int main() {
    PriorityQueue emergency;
    emergency.enqueue("P101", 3);
    emergency.enqueue("P102", 1);
    emergency.enqueue("P103", 2);
    emergency.display();
    emergency.treatNext();
    emergency.display();
    return 0;
}
