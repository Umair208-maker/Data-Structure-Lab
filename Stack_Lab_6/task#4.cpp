
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
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
            cout << "Processed order: "
                 << temp->orderID << endl;
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
                cout << current->orderID << endl;
                current = current->next;
            }
        }
    }

    void showTop() {
        if (top == NULL) {
            cout << "No order available." << endl;
        } else {
            cout << "Current TOP order: "
                 << top->orderID << endl;
        }
    }

    bool isEmpty() {
        return top == NULL;
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

    s.push("ORD-101");
    s.push("ORD-102");
    s.push("ORD-103");
    s.push("ORD-104");

    cout << "Restaurant Orders (TOP to Bottom):" << endl;
    s.display();

    cout << "\nProcessing two orders:" << endl;
    s.pop();
    s.pop();

    cout << "\n";
    s.showTop();

    cout << "\nRemaining Orders:" << endl;
    s.display();

    cout << "\nChecking Stack Status:" << endl;
    if (s.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}

