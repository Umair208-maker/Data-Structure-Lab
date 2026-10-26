#include <iostream>
using namespace std;

class Node {
public:
    string productID;
    Node* next;
};

int main() {

    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    
    head->productID = "P101";
    second->productID = "P205";
    third->productID = "P310";
    fourth->productID = "P415";

    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    
    Node* current = head;

    cout << "Shopping Cart:" << endl;

    while (current != NULL) {

        cout << current->productID;

        if (current->next != NULL) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;

    
    string removeID;

    cout << "Remove Product: ";
    cin >> removeID;

    
    if (head->productID == removeID) {

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {

        
        current = head;

        while (current->next != NULL) {

            if (current->next->productID == removeID) {

                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;

                break;
            }

            current = current->next;
        }
    }

    
    cout << "Updated Cart:" << endl;

    current = head;

    while (current != NULL) {

        cout << current->productID;

        if (current->next != NULL) {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;

    return 0;
}
