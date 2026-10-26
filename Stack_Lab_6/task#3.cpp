
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow!" << endl;
        } else {
            Node* temp = top;
            cout << "Handled request: "
                 << temp->patientID << endl;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
        } else {
            Node* current = top;

            while (current != NULL) {
                cout << current->patientID << endl;
                current = current->next;
            }
        }
    }

    void showTop() {
        if (top == NULL) {
            cout << "No request available." << endl;
        } else {
            cout << "New TOP request: "
                 << top->patientID << endl;
        }
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push("P101");
    s.push("P102");
    s.push("P103");
    s.push("P104");

    cout << "Emergency Requests (TOP to Bottom):" << endl;
    s.display();

    cout << "\nProcessing latest request:" << endl;
    s.pop();

    cout << "\n";
    s.showTop();

    cout << "\nRemaining Requests:" << endl;
    s.display();

    return 0;
}

