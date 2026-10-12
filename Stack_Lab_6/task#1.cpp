
#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            pages[top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << "Back button removed: " << pages[top] << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            for (int i = top; i >= 0; i--) {
                cout << pages[i] << endl;
            }
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "No page available." << endl;
        } else {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push("Google");
    s.push("YouTube");
    s.push("Facebook");
    s.push("GitHub");

    cout << "Browsing History (TOP to Bottom):" << endl;
    s.display();

    cout << "\nPerforming POP operation:" << endl;
    s.pop();

    cout << "\n";
    s.showTop();

    cout << "\nRemaining Browsing History:" << endl;
    s.display();

    return 0;
}


